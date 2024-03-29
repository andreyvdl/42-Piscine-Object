#include "Bank.hpp"

const double	Bank::_bankPart = 0.05;

static void	deleteAllClients(vector< Account* >& clients);
static const Account*	getAccount(size_t id, vector< Account* >& accounts);

Bank::Bank(): _liquidity(0) {};

Bank::Bank(Bank const& that): _liquidity(0)
{
	*this = that;
}

Bank::~Bank()
{
	deleteAllClients(this->_clientAccounts);
}

Bank&	Bank::operator=(Bank const& that)
{
	if (this != &that) {
		this->_liquidity = that.getLiquidity();
		deleteAllClients(this->_clientAccounts);
		for (vector< Account* >::iterator b = const_cast< vector< Account* >& >(that._clientAccounts).begin(); \
			b != that._clientAccounts.end(); \
			b++
		) {
			this->_clientAccounts.push_back(new Account(**b));
		}
	}
	return *this;
}

double	Bank::getLiquidity() const
{
	return this->_liquidity;
}

void	Bank::setLiquidity(double liquidity)
{
	this->_liquidity = liquidity;
}

void	Bank::createAccount(size_t id, double value)
{
	if (value < 0) {
		cerr << "Accounts can't start with negative values" << endl;
	}
	for (vector< Account* >::iterator b = this->_clientAccounts.begin(); \
		b != this->_clientAccounts.end(); \
		b++
	) {
		if ((*b)->getId() == id) {
			cerr << "ID already exists" << endl;
			return ;
		}
	}
	this->_clientAccounts.push_back(new Account(id, value));
}

void	Bank::deleteAccount(size_t id)
{
	for (vector< Account* >::iterator b = this->_clientAccounts.begin(); \
		b != this->_clientAccounts.end(); \
		b++
	) {
		if ((*b)->getId() == id) {
			delete *b;
			*b = NULL;
			this->_clientAccounts.erase(b);
			return ;
		}
	}
	cerr << "ID not found" << endl;
}

void	Bank::deposit(size_t id, double amount)
{
	Account*	account = \
		const_cast< Account* >(getAccount(id, this->_clientAccounts));
	double	interest = 0;

	if (amount <= 0) {
		cerr << "Deposits can't be negative or zero" << endl;
		return ;
	} else if (account == NULL) {
		cerr << "Account not found" << endl;
		return ;
	}
	interest = amount * const_cast< double& >(this->_bankPart);
	amount -= interest;
	this->setLiquidity(this->_liquidity + interest);
	account->_value += amount;
}

void	Bank::withdraw(size_t id, double amount)
{
	Account*	account = \
		const_cast< Account* >(getAccount(id, this->_clientAccounts));

	if (amount <= 0) {
		cerr << "What are you trying to do?" << endl;
		return ;
	} else if (account == NULL) {
		cerr << "Account not found" << endl;
		return ;
	} else if (account->_value < amount) {
		cerr << "Not enough money for withdraw" << endl;
		return ;
	}
	account->_value = account->_value - amount;
}

void	Bank::loan(size_t id, double amount)
{
	Account*	account = \
		const_cast< Account* >(getAccount(id, this->_clientAccounts));
	double	interest = 0;

	if (amount <= 0) {
		cerr << "Cannot loan negative or zero" << endl;
		return ;
	} else if (account == NULL) {
		cerr << "Account not found" << endl;
		return ;
	} else if (this->_liquidity < amount) {
		cerr << "Cannot loan this amount" << endl;
		return ;
	}
	interest = amount * const_cast< double& >(this->_bankPart);
	amount -= interest;
	this->_liquidity += interest;
	account->_value += amount;
}

void	Bank::printClients(ostream& output) const
{
	vector< Account* > clients = this->_clientAccounts;
	for (vector< Account* >::iterator b = const_cast< vector< Account* >& >(this->_clientAccounts).begin(); \
		b != this->_clientAccounts.end(); \
		b++
	) {
		output << **b << endl;
	}
}

void	Bank::addAccount(Account* account)
{
	for (vector< Account* >::iterator b = this->_clientAccounts.begin(); \
		b != this->_clientAccounts.end(); \
		b++
	) {
		if ((*b)->getId() == account->getId()) {
			cerr << "ID already exists, create a new account on our bank" << endl;
			return ;
		}
	}
	this->_clientAccounts.push_back(new Account(*account));
}

ostream&	operator<<(ostream& p_os, const Bank& p_bank)
{
	p_os << "bank informations : " << endl;
	p_os << "liquidity : " << p_bank.getLiquidity() << endl;
	p_bank.printClients(p_os);
	return p_os;
}

static void	deleteAllClients(vector< Account* >& clients)
{
	vector < Account* >::iterator b = clients.begin();

	while (b != clients.end()) {
		if (*b != NULL) {
			delete *b;
			*b = NULL;
			clients.erase(b);
		} else {
			b++;
		}
	}
}

static const Account*	getAccount(size_t id, vector< Account* >& accounts)
{
	for (vector< Account* >::iterator b = accounts.begin(); \
		b != accounts.end(); \
		b++
	) {
		if ((*b)->getId() == id) {
			return *b;
		}
	}
	return NULL;
}
