/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:51:10 by adantas-          #+#    #+#             */
/*   Updated: 2024/08/08 16:22:04 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Worker.hpp"
#include <sstream>

Worker::Worker():
_coordonnee(Position()), _stat(Statistic()), _shovel(NULL)
{
	// std::cerr << "New Worker created!" << std::endl;
}

Worker::Worker(const Worker& that):
_coordonnee(Position()), _stat(Statistic()), _shovel(NULL)
{
	// std::cerr << "New Worker copied!" << std::endl;
	*this = that;
}

Worker::Worker(Position pos, Statistic stat, Shovel* shovel):
_coordonnee(pos), _stat(stat), _shovel(shovel)
{
	// std::cerr << "New Worker with values!" << std::endl;
}

Worker::~Worker()
{
	// std::cerr << "Worker deleted!" << std::endl;
}

Worker& Worker::operator=(const Worker& that)
{
	// std::cerr << "Worker =operator!" << std::endl;
	if (this != &that) {
		this->_coordonnee = that._coordonnee;
		this->_stat = that._stat;
		this->_shovel = that._shovel;
	}

	return *this;
}

void Worker::pickShovel(Shovel* shovel)
{
	std::cerr << "Trying picking shovel... ";
	std::cerr << (shovel != NULL ? "SUCCESS!" : "FAILED!") << std::endl;

	this->_shovel = shovel;
}

void Worker::removeShovel()
{
	std::cerr << "Shovel removed!" << std::endl;
	this->_shovel = NULL;
}

Position Worker::getCoordonnee() const
{
	// std::cerr << "Worker const coordonnee getter!" << std::endl;
	return this->_coordonnee;
}

Position Worker::getCoordonnee()
{
	// std::cerr << "Worker coordonnee getter!" << std::endl;
	return this->_coordonnee;
}

Statistic Worker::getStat() const
{
	// std::cerr << "Worker const stat getter!" << std::endl;
	return this->_stat;
}

Statistic Worker::getStat()
{
	// std::cerr << "Worker stat getter!" << std::endl;
	return this->_stat;
}

std::ostream& operator<<(std::ostream& os, const Worker& that)
{
	std::stringstream ss;
	// std::cerr << "Worker <<operator!" << std::endl;
	ss << "Worker attributes:" << std::endl;
	ss << "Coordonee: " << that.getCoordonnee() << "Stat: " << that.getStat()
		<< "Shovel: " << that.getShovel() << std::endl << *that.getShovel();
	os << ss.str();
	return os;
}
