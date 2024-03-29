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
		static const double	_bankPart;
	public:
			Bank();
			Bank(Bank const& that);
			~Bank();
		Bank&	operator=(Bank const& that);
		double	getLiquidity() const;
		void	setLiquidity(double liquidity);
		void	addAccount(Account* account);
		void	createAccount(size_t id, double value);
		void	deleteAccount(size_t id);
		void	deposit(size_t id, double amount);
		void	withdraw(size_t id, double amount);
		void	loan(size_t id, double amount);
		void	printClients(ostream& output) const;
};

ostream&	operator<<(ostream& p_os, const Bank& p_bank);

#endif
