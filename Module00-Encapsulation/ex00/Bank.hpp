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
		const double	_bankPart = 0.05;
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
		void	loan(size_t id, double amount);
};

// pass this to the cpp file
ostream&	operator<<(ostream& p_os, const Bank& p_bank);

#endif
