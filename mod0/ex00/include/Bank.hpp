/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:36:44 by adantas-          #+#    #+#             */
/*   Updated: 2024/08/05 17:13:50 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BANK_HPP
# define BANK_HPP 42
#include "Account.hpp"

class Bank
{
private:
	double			_liquidity;
	t_account		_clients; // isso vai me dar dor de cabeça depois

public:
	Bank(void): _liquidity(0.0), _clients( t_account() ) {}

	void			addClient(double deposit);
	void			removeClient(size_t id);
	void			depositTo(double amount, size_t id);
	void			withdrawFrom(double amount, size_t id);
	void			giveLoan(double amount, size_t id);
	t_account_cit	begin(void) const { return this->_clients.begin(); }
	t_account_cit	end(void) const { return this->_clients.end(); }
	t_account_it	begin(void) { return this->_clients.begin(); }
	t_account_it	end(void) { return this->_clients.end(); }

	const double	getLiquidity(void) const { return this->_liquidity; }
	const Account*	getAccount(size_t id) const;
	double			getLiquidity(void) { return this->_liquidity; }
	Account*		getAccount(size_t id);
};

#endif
