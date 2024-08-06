/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:38:43 by adantas-          #+#    #+#             */
/*   Updated: 2024/08/05 23:05:58 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>
#include "../include/Bank.hpp"

void Bank::addClient(double deposit)
{
	if (deposit < 0.0) {
		std::cerr << "ERROR: Can't deposit negative values!" << std::endl;
		return;
	}

	double bank_tax = deposit * 0.05;

	this->_liquidity += bank_tax;
	this->_clients.push_back( new Account(Account::_auto_increment++, deposit - bank_tax) );
}

void Bank::removeClient(size_t id)
{
	for (t_account_it it = this->begin(); it != this->end(); it++) {
		if (id == (*it)->_id) {
			this->_clients.erase(it);
			return;
		}
	}
	std::cerr << "ERROR: Client id not found!" << std::endl;
}

void Bank::depositTo(double amount, size_t id)
{
	if (amount < 0.0) {
		std::cerr << "ERROR: Can't deposit negative values!" << std::endl;
		return;
	}
	for (t_account_it it = this->begin(); it != this->end(); it++) {
		if (id == (*it)->_id) {
			double bank_tax = amount * 0.05;

			this->_liquidity += bank_tax;
			(*it)->_money += amount - bank_tax;
			return;
		}
	}
	std::cerr << "ERROR: Client id not found!" << std::endl;
}

void Bank::withdrawFrom(double amount, size_t id)
{
	if (amount < 0.0) {
		std::cerr << "ERROR: Can't withdraw negative values!" << std::endl;
		return;
	}
	for (t_account_it it = this->begin(); it != this->end(); it++) {
		if (id == (*it)->_id) {
			if (amount > (*it)->_money) {
				std::cerr << "ERROR: Not enough cash, stranger!" << std::endl;
				return;
			}
			(*it)->_money -= amount;
			return;
		}
	}
	std::cerr << "ERROR: Client id not found!" << std::endl;
}

void Bank::giveLoan(double amount, size_t id)
{
	if (amount < 0.0) {
		std::cerr << "ERROR: Can't loan negative values!" << std::endl;
		return;
	}
	else if (amount > this->_liquidity) {
		std::cerr << "ERROR: Your loan request was denied!" << std::endl;
		return;
	}
	for (t_account_it it = this->begin(); it != this->end(); it++) {
		if (id == (*it)->_id) {
			(*it)->_money += amount;
			this->_liquidity -= amount;
			return;
		}
	}
}

Account* Bank::getAccount(size_t id) const
{
	for (t_account_cit it = this->begin(); it != this->end(); it++) {
		if (id == (*it)->_id) return *it;
	}
	std::cerr << "ERROR: Client id not found!" << std::endl;
	return NULL;
}

Account* Bank::getAccount(size_t id)
{
	for (t_account_it it = this->begin(); it != this->end(); it++) {
		if (id == (*it)->_id) return *it;
	}
	std::cerr << "ERROR: Client id not found!" << std::endl;
	return NULL;
}

std::ostream& operator<<(std::ostream& os, const Bank& that)
{
	os << "Bank informations: " << std::endl;
	os << "Liquidity:" << that.getLiquidity() << std::endl;
	for (t_account_cit it = that.begin(); it != that.end(); it++)
		os << (**it) << std::endl;
	
	return os;
}




