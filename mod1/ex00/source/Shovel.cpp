/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shovel.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:12:56 by adantas-          #+#    #+#             */
/*   Updated: 2024/08/14 15:44:31 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Shovel.hpp"
#include <sstream>

Shovel::Shovel():
Tool()
{
#ifdef DEBUG
	std::cerr << "New Shovel created!" << std::endl;
#endif
}

Shovel::Shovel(const Shovel& that):
Tool()
{
#ifdef DEBUG
	std::cerr << "New Shovel copied!" << std::endl;
#endif
	*this = that;
}

Shovel::Shovel(const size_t uses):
Tool(uses)
{
#ifdef DEBUG
	std::cerr << "New Shovel with values created!" << std::endl;
#endif
}

Shovel::~Shovel()
{
#ifdef DEBUG
	std::cerr << "Shovel deleted!" << std::endl;
#endif
}

Shovel& Shovel::operator=(const Shovel& that)
{
#ifdef DEBUG
	std::cerr << "Shovel =operator!" << std::endl;
#endif
	if (this != &that) {
		this->_numberOfUses = that._numberOfUses;
	}

	return *this;
}

void Shovel::use()
{
	if (this->_numberOfUses == 0) {
		std::cerr << "Can't use this shovel!" << std::endl;
		return;
	}
	std::cerr << "Shovel used!" << std::endl;
	--this->_numberOfUses;
}

std::ostream& operator<<(std::ostream& os, const Shovel& that)
{
	std::stringstream ss;
#ifdef DEBUG
	std::cerr << "Shovel <<operator!" << std::endl;
#endif
	ss << "Shovel attributes:" << std::endl;
	ss << "NumberOfUses: " << that.getNbrOfUses() << std::endl;
	os << ss.str();
	return os;
}
