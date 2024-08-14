/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Position.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:36:53 by adantas-          #+#    #+#             */
/*   Updated: 2024/08/14 15:40:17 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Position.hpp"
#include <sstream>

Position::Position():
_x(0), _y(0), _z(0)
{
#ifdef DEBUG
	std::cerr << "New Postion created!" << std::endl;
#endif
}

Position::Position(const int x, const int y, const int z):
_x(x), _y(y), _z(z)
{
#ifdef DEBUG
	std::cerr << "New Position with values created!" << std::endl;
#endif
}

Position::Position(const Position& that):
_x(0), _y(0), _z(0)
{
#ifdef DEBUG
	std::cerr << "New Position copied!" << std::endl;
#endif
	*this = that;
}

Position::~Position()
{
#ifdef DEBUG
	std::cerr << "Position deleted!" << std::endl;
#endif
}

Position& Position::operator=(const Position& that)
{
#ifdef DEBUG
	std::cerr << "Position =operator!" << std::endl;
#endif
	if (this != &that) {
		this->_x = that._x;
		this->_y = that._y;
		this->_z = that._z;
	}

	return *this;
}

int Position::getX() const
{
#ifdef DEBUG
	std::cerr << "Position const X getter!" << std::endl;
#endif
	return this->_x;
}

int Position::getX()
{
#ifdef DEBUG
	std::cerr << "Position X getter!" << std::endl;
#endif
	return this->_x;
}

int Position::getY() const
{
#ifdef DEBUG
	std::cerr << "Position const Y getter!" << std::endl;
#endif
	return this->_y;
}

int Position::getY()
{
#ifdef DEBUG
	std::cerr << "Position Y getter!" << std::endl;
#endif
	return this->_y;
}

int Position::getZ() const
{
#ifdef DEBUG
	std::cerr << "Position const Z getter!" << std::endl;
#endif
	return this->_z;
}

int Position::getZ()
{
#ifdef DEBUG
	std::cerr << "Position Z getter!" << std::endl;
#endif
	return this->_z;
}

std::ostream& operator<<(std::ostream& os, const Position& that)
{
	std::stringstream ss;
#ifdef DEBUG
	std::cerr << "Position <<operator!" << std::endl;
#endif
	ss << "Position attribtes:" << std::endl;
	ss << "X: " << that.getX() << " Y: " << that.getY() << " Z: "
		<< that.getZ() << std::endl;
	os << ss.str();
	return os;
}
