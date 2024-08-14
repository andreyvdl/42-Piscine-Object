/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Statistic.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:58:49 by adantas-          #+#    #+#             */
/*   Updated: 2024/08/14 16:16:05 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Statistic.hpp"
#include <sstream>

Statistic::Statistic():
_level(1), _exp(0)
{
#ifdef DEBUG
	std::cerr << "New Statistic created!" << std::endl;
#endif
}

Statistic::Statistic(const Statistic& that):
_level(1), _exp(0)
{
#ifdef DEBUG
	std::cerr << "New Statistic copied!" << std::endl;
#endif
	*this = that;
}

Statistic::Statistic(const int level, const int exp):
_level(level), _exp(exp)
{
#ifdef DEBUG
	std::cerr << "New Statistic with values!" << std::endl;
#endif
}

Statistic::~Statistic()
{
#ifdef DEBUG
	std::cerr << "Statistic deleted!" << std::endl;
#endif
}

Statistic& Statistic::operator=(const Statistic& that)
{
#ifdef DEBUG
	std::cerr << "Statistic =operator!" << std::endl;
#endif
	if (this != &that) {
		this->_level = that._level;
		this->_exp = that._exp;
	}

	return *this;
}

int Statistic::getLevel() const
{
#ifdef DEBUG
	std::cerr << "Statistic const level getter!" << std::endl;
#endif
	return this->_level;
}

int Statistic::getLevel()
{
#ifdef DEBUG
	std::cerr << "Statistic level getter!" << std::endl;
#endif
	return this->_level;
}

int Statistic::getExp() const
{
#ifdef DEBUG
	std::cerr << "Statistic const exp getter!" << std::endl;
#endif
	return this->_exp;
}

int Statistic::getExp()
{
#ifdef DEBUG
	std::cerr << "Statistic exp getter!" << std::endl;
#endif
	return this->_exp;
}

std::ostream& operator<<(std::ostream& os, const Statistic& that)
{
	std::stringstream ss;
#ifdef DEBUG
	std::cerr << "Statistic <<operator!" << std::endl;
#endif
	ss << "Statistic attributes:" << std::endl;
	ss << "Level: " << that.getLevel() << " Exp: " << that.getExp()
		<< std::endl;
	os << ss.str();
	return os;
}
