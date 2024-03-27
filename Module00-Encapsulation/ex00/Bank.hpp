#pragma once
#ifndef BANK_HPP
#	define BANK_HPP

#	include <iostream>
#	include <vector>
#	include <map>

using namespace std;

#	define  TClientAccount map< int, Account* >

class Bank
{
	private:
		TClientAccount	clientAccounts;
		int	liquidity;
	public:
			Bank(void);
			~Bank(void);
		TClientAccount const	getClientAccounts(void) const;
		int const	getLiquidity(void) const;
};

// pass this to the cpp file
ostream&	operator<<(ostream& p_os, const Bank& p_bank)
{
	p_os << "bank informations : " << endl;
	p_os << "liquidity : " << p_bank.getLiquidity() << endl;
	for (TClientAccount::iterator b = p_bank.getClientAccounts().begin(); \
		b != p_bank.getClientAccounts().end(); \
		b++
	) {
		p_os << *b << endl;
	}
	return p_os;
}

#endif
