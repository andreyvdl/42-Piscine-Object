/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:32:29 by adantas-          #+#    #+#             */
/*   Updated: 2024/08/05 17:14:02 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/Account.hpp"

size_t Account::_auto_increment = 0;

std::ostream& operator<<(std::ostream& os, const Account& that)
{
	os << "[" << that.getId() << "] - ["<< that.getMoney() << "]";

	return os;
}
