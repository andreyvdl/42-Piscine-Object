#pragma once
#ifndef ACCOUNT_HPP
#	define ACCOUNT_HPP

#	include <iostream>

using namespace std;

class	Account
{
	private:
		size_t	_id;
		double	_value;
			Account();
	public:
			Account(size_t id, double value);
			Account(Account const& that);
			~Account();
		Account&	operator=(Account const& that);
		size_t	getId() const;
		double	getValue() const;

	friend class Bank;
};

ostream&	operator<<(ostream& p_os, const Account& p_account);

#endif
