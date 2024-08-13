/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATool.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:02:16 by adantas-          #+#    #+#             */
/*   Updated: 2024/08/13 12:34:17 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ATool.hpp"

Tool::Tool():
_numberOfUses(0)
{
	// std::cerr << "Tool created!" << std::endl;
}

Tool::Tool(size_t uses):
_numberOfUses(uses)
{
	// std::cerr << "Tool with values created!" << std::endl;
}

size_t Tool::getNbrOfUses() const
{
	// std::cerr << "nbrOfUses const getter!" << std::endl;
	return this->_numberOfUses;
}

size_t Tool::getNbrOfUses()
{
	// std::cerr << "nbrOfUses getter!" << std::endl;
	return this->_numberOfUses;
}

std::ostream& operator<<(std::ostream& os, const Tool& that)
{
	os << "Uses: " << that.getNbrOfUses() << std::endl;
	return os;
}
