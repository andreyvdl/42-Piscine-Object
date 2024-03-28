#pragma once
#ifndef BANK_HPP
#	define BANK_HPP

#	include <iostream>
#	include <vector>
#	include <map>
#	include "Account.hpp"

class Bank
{
	private:
		vector< Account* >	_clientAccounts;
		double	_liquidity;
	public:
			Bank();
			Bank(Bank const& that);
			~Bank();
		Bank&	operator=(Bank const& that);
		vector< Account* > const&	getClientAccounts() const;
		Account* const	getAccount(size_t id);
		double const	getLiquidity() const;
		void	setLiquidity(double liquidity);
		void	createAccount(size_t id, double value);
		void	deleteAccount(size_t id);
		void	deposit(size_t id, double amount);
		void	withdraw(size_t id, double amount);
		void	transfer(size_t from, size_t to, double amount);
		void	loan(size_t id, double amount);
};

// pass this to the cpp file
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

#endif
