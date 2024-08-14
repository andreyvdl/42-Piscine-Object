/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATool.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:02:16 by adantas-          #+#    #+#             */
/*   Updated: 2024/08/14 15:36:35 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ATool.hpp"

Tool::Tool():
_numberOfUses(0)
{
#ifdef DEBUG
	std::cerr << "Tool created!" << std::endl;
#endif
}

Tool::Tool(size_t uses):
_numberOfUses(uses)
{
#ifdef DEBUG
	std::cerr << "Tool with values created!" << std::endl;
#endif
}

size_t Tool::getNbrOfUses() const
{
#ifdef DEBUG
	std::cerr << "nbrOfUses const getter!" << std::endl;
#endif
	return this->_numberOfUses;
}

size_t Tool::getNbrOfUses()
{
#ifdef DEBUG
	std::cerr << "nbrOfUses getter!" << std::endl;
#endif
	return this->_numberOfUses;
}

std::ostream& operator<<(std::ostream& os, const Tool& that)
{
#ifdef DEBUG
	std::cerr << "Tool <<operator!" << std::endl;
#endif
	os << "Uses: " << that.getNbrOfUses() << std::endl;
	return os;
}
