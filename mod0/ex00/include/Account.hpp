/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:53 by adantas-          #+#    #+#             */
/*   Updated: 2024/08/05 23:07:44 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCOUNT_HPP
# define ACCOUNT_HPP 42
# include <cstdlib>
# include <vector>
# include <iostream>

class Account
{
private:
	size_t			_id;
	double			_money;
	static size_t	_auto_increment;

	Account(size_t id, double deposit): _id(id), _money(deposit) {}
	Account(void);
	Account(const Account& that);

	friend class Bank;

public:

	size_t	getId(void) const { return this->_id; }
	double	getMoney(void) const { return this->_money; }
	size_t	getId(void) { return this->_id; }
	double	getMoney(void) { return this->_money; }
};

std::ostream& operator<<(std::ostream& os, const Account& that);

typedef std::vector<Account*>					t_account;
typedef std::vector<Account*>::iterator			t_account_it;
typedef std::vector<Account*>::const_iterator	t_account_cit;

#endif
