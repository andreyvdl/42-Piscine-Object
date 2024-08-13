/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shovel.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:12:56 by adantas-          #+#    #+#             */
/*   Updated: 2024/08/12 18:11:22 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Shovel.hpp"
#include <sstream>

Shovel::Shovel():
Tool()
{
	// std::cerr << "New Shovel created!" << std::endl;
	
}

Shovel::Shovel(const Shovel& that):
Tool()
{
	// std::cerr << "New Shovel copied!" << std::endl;
	*this = that;
}

Shovel::Shovel(const size_t uses):
Tool(uses)
{
	// std::cerr << "New Shovel with values created!" << std::endl;
}

Shovel::~Shovel()
{
	// std::cerr << "Shovel deleted!" << std::endl;
}

Shovel& Shovel::operator=(const Shovel& that)
{
	// std::cerr << "Shovel =operator!" << std::endl;
	if (this != &that) {
		this->_numberOfUses = that._numberOfUses;
	}

	return *this;
}

void Shovel::use()
{
	if (this->_numberOfUses == 0) {
		// std::cerr << "Can't use this shovel!" << std::endl;
		return;
	}
	// std::cerr << "Shovel used!" << std::endl;
	--this->_numberOfUses;
}

std::ostream& operator<<(std::ostream& os, const Shovel& that)
{
	std::stringstream ss;
	// std::cerr << "Shovel <<operator!" << std::endl;
	ss << "Shovel attributes:" << std::endl;
	ss << "NumberOfUses: " << that.getNbrOfUses() << std::endl;
	os << ss.str();
	return os;
}
