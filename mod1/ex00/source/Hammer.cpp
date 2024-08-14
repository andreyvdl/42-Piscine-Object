/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hammer.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:40:34 by adantas-          #+#    #+#             */
/*   Updated: 2024/08/14 15:38:04 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Hammer.hpp"
#include <sstream>

Hammer::Hammer():
Tool()
{
#ifdef DEBUG
	std::cerr << "New Hammer created!" << std::endl;
#endif
}

Hammer::Hammer(const Hammer& that):
Tool()
{
#ifdef DEBUG
	std::cerr << "New Hammer copied!" << std::endl;
#endif
	*this = that;
}

Hammer::Hammer(const size_t uses):
Tool(uses)
{
#ifdef DEBUG
	std::cerr << "New Hammer with values created!" << std::endl;
#endif
}

Hammer::~Hammer()
{
#ifdef DEBUG
	std::cerr << "Hammer deleted!" << std::endl;
#endif
};

Hammer& Hammer::operator=(const Hammer& that)
{
#ifdef DEBUG
	std::cerr << "Hammer =operator!" << std::endl;
#endif
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
#ifdef DEBUG
	std::cerr << "Hammer <<operator!" << std::endl;
#endif
	ss << "Hammer attributes:" << std::endl;
	ss << "NumberOfUses: " << that.getNbrOfUses() << std::endl;
	os << ss.str();
	return os;
}
