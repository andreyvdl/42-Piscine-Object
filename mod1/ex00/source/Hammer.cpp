/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hammer.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:40:34 by adantas-          #+#    #+#             */
/*   Updated: 2024/08/12 18:45:36 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Hammer.hpp"
#include <sstream>

Hammer::Hammer():
Tool()
{
	std::cerr << "New Hammer created!" << std::endl;
}

Hammer::Hammer(const Hammer& that):
Tool()
{
	std::cerr << "New Hammer copied!" << std::endl;
	*this = that;
}

Hammer::Hammer(const size_t uses):
Tool(uses)
{
	std::cerr << "New Hammer with values created!" << std::endl;
}

Hammer::~Hammer()
{
	std::cerr << "Hammer deleted!" << std::endl;
};

Hammer& Hammer::operator=(const Hammer& that)
{
	std::cerr << "Hammer =operator!" << std::endl;
	if (this != &that)
		this->_numberOfUses = that._numberOfUses;

	return *this;
}

void Hammer::use()
{
	if (this->_numberOfUses == 0) {
		std::cerr << "Can't use this hammer!" << std::endl;
		return;
	}
	std::cerr << "Hammer used!" << std::endl;
	--this->_numberOfUses;
}

std::ostream& operator<<(std::ostream& os, const Hammer& that)
{
	std::stringstream ss;
	std::cerr << "Hammer <<operator!" << std::endl;
	ss << "Hammer attributes:" << std::endl;
	ss << "NumberOfUses: " << that.getNbrOfUses() << std::endl;
	os << ss.str();
	return os;
}
