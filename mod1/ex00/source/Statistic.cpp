/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Statistic.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:58:49 by adantas-          #+#    #+#             */
/*   Updated: 2024/08/08 13:58:39 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Statistic.hpp"
#include <sstream>

Statistic::Statistic():
_level(1), _exp(0)
{
	// std::cerr << "New Statistic created!" << std::endl;
}

Statistic::Statistic(const Statistic& that):
_level(1), _exp(0)
{
	// std::cerr << "New Statistic copied!" << std::endl;
	*this = that;
}

Statistic::Statistic(const int level, const int exp):
_level(level), _exp(exp)
{
	// std::cerr << "New Statistic with values!" << std::endl;
}

Statistic::~Statistic()
{
	// std::cerr << "Statistic deleted!" << std::endl;
}

Statistic& Statistic::operator=(const Statistic& that)
{
	// std::cerr << "Statistic =operator!" << std::endl;
	if (this != &that) {
		this->_level = that._level;
		this->_exp = that._exp;
	}

	return *this;
}

int Statistic::getLevel() const
{
	// std::cerr << "Statistic const level getter!" << std::endl;
	return this->_level;
}

int Statistic::getLevel()
{
	// std::cerr << "Statistic level getter!" << std::endl;
	return this->_level;
}

int Statistic::getExp() const
{
	// std::cerr << "Statistic const exp getter!" << std::endl;
	return this->_exp;
}

int Statistic::getExp()
{
	// std::cerr << "Statistic exp getter!" << std::endl;
	return this->_exp;
}

std::ostream& operator<<(std::ostream& os, const Statistic& that)
{
	std::stringstream ss;
	// std::cerr << "Statistic <<operator!" << std::endl;
	ss << "Statistic attributes:" << std::endl;
	ss << "Level: " << that.getLevel() << " Exp: " << that.getExp()
		<< std::endl;
	os << ss.str();
	return os;
}
