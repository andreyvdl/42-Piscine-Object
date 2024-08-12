/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:51:10 by adantas-          #+#    #+#             */
/*   Updated: 2024/08/12 15:45:15 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Worker.hpp"
#include <sstream>

std::map<Shovel*, Worker*> Worker::_helper = std::map<Shovel*, Worker*>();

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
	if (shovel != NULL)
		this->_helper.insert(std::pair<Shovel*, Worker*>(shovel, this));
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
		this->pickShovel(that._shovel);
	}

	return *this;
}

void Worker::pickShovel(Shovel* shovel)
{
	if (shovel == NULL) {
		std::cerr << "No shovel to pickup!" << std::endl;
		return;
	}

	std::map<Shovel*, Worker*>::iterator it = this->_helper.find(shovel);
	if (it == this->_helper.end()) {
		// std::cerr << "Shovel picked!" << std::endl;
		this->_helper.insert(std::pair<Shovel*, Worker*>(shovel, this));
		this->_shovel = shovel;
	}

	else {
		std::cerr << "Hey bro, i need this shovel!" << std::endl;
		it->second->removeShovel(shovel);
		this->_helper.insert(std::pair<Shovel*, Worker*>(shovel, this));
		this->_shovel = shovel;
	}

}

void Worker::removeShovel(Shovel* shovel)
{
	std::cerr << "Shovel removed!" << std::endl;
	this->_helper.erase(shovel);
	this->_shovel = NULL;
}

Shovel* Worker::getShovel() const
{
	// std::cerr << "Worker const shovel getter!" << std::endl;
	return this->_shovel;
}

Shovel* Worker::getShovel()
{
	// std::cerr << "Worker shovel getter!" << std::endl;
	return this->_shovel;
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
		<< "Shovel: " << that.getShovel();
	if (that.getShovel() != NULL)
		ss << std::endl << *that.getShovel();

	os << ss.str();
	return os;
}
