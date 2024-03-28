#include "Bank.hpp"

static void	deleteAllClients(vector< Account* >& clients);

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
		for (vector< Account* >::const_iterator b = \
				that.getClientAccounts().begin(); \
			b != that.getClientAccounts().end(); \
			b++
		) {
			this->_clientAccounts.push_back(new Account(**b));
		}
	}
	return *this;
}

vector< Account* > const&	Bank::getClientAccounts() const
{
	return this->_clientAccounts;
}

Account* const	Bank::getAccount(size_t id)
{
	for (vector< Account* >::iterator b = this->_clientAccounts.begin(); \
		b != this->_clientAccounts.end(); \
		b++
	) {
		if ((*b)->getId() == id) {
			return *b;
		}
	}
	return NULL;
}

double const	Bank::getLiquidity() const
{
	return this->_liquidity;
}

void	Bank::setLiquidity(double liquidity)
{
	this->_liquidity = liquidity;
}

void	Bank::createAccount(size_t id, double value)
{
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
			this->_clientAccounts.erase(b);
			return ;
		}
	}
	cerr << "ID not found" << endl;
}

void	Bank::deposit(size_t id, double amount);
void	Bank::withdraw(size_t id, double amount);
void	Bank::transfer(size_t from, size_t to, double amount);
void	Bank::loan(size_t id, double amount);

ostream&	operator<<(ostream& p_os, const Bank& p_bank)
{
	p_os << "bank informations : " << endl;
	p_os << "liquidity : " << p_bank.getLiquidity() << endl;
	for (vector< Account* >::iterator b = p_bank.getClientAccounts().begin(); \
		b != p_bank.getClientAccounts().end(); \
		b++
	) {
		p_os << *b << endl;
	}
	return p_os;
}

static void	deleteAllClients(vector< Account* >& clients)
{
	for (vector< Account* >::iterator b = clients.begin(); \
		b != clients.end(); \
		b++
	) {
		if (*b != NULL) {
			delete *b;
		}
	}
}
