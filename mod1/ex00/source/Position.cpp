/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Position.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:36:53 by adantas-          #+#    #+#             */
/*   Updated: 2024/08/08 13:58:08 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Position.hpp"
#include <sstream>

Position::Position():
_x(0), _y(0), _z(0)
{
	// std::cerr << "New Postion created!" << std::endl;
}

Position::Position(const int x, const int y, const int z):
_x(x), _y(y), _z(z)
{
	// std::cerr << "New Position with values created!" << std::endl;
}

Position::Position(const Position& that):
_x(0), _y(0), _z(0)
{
	// std::cerr << "New Position copied!" << std::endl;
	*this = that;
}

Position::~Position()
{
	// std::cerr << "Position deleted!" << std::endl;
}

Position& Position::operator=(const Position& that)
{
	// std::cerr << "Position =operator!" << std::endl;
	if (this != &that) {
		this->_x = that._x;
		this->_y = that._y;
		this->_z = that._z;
	}

	return *this;
}

int Position::getX() const
{
	// std::cerr << "Position const X getter!" << std::endl;
	return this->_x;
}

int Position::getX()
{
	// std::cerr << "Position X getter!" << std::endl;
	return this->_x;
}

int Position::getY() const
{
	// std::cerr << "Position const Y getter!" << std::endl;
	return this->_y;
}

int Position::getY()
{
	// std::cerr << "Position Y getter!" << std::endl;
	return this->_y;
}

int Position::getZ() const
{
	// std::cerr << "Position const Z getter!" << std::endl;
	return this->_z;
}

int Position::getZ()
{
	// std::cerr << "Position Z getter!" << std::endl;
	return this->_z;
}

std::ostream& operator<<(std::ostream& os, const Position& that)
{
	std::stringstream ss;
	// std::cerr << "Position <<operator!" << std::endl;
	ss << "Position attribtes:" << std::endl;
	ss << "X: " << that.getX() << " Y: " << that.getY() << " Z: "
		<< that.getZ() << std::endl;
	os << ss.str();
	return os;
}
