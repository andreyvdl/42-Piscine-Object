/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hammer.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:26:02 by adantas-          #+#    #+#             */
/*   Updated: 2024/08/12 18:42:17 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HAMMER_HPP
# define HAMMER_HPP
# include "ATool.hpp"
# include <iostream>

class Hammer: public Tool
{
public:
	Hammer();
	Hammer(const Hammer& that);
	Hammer(const size_t uses);
	~Hammer();

	Hammer& operator=(const Hammer& that);

	void use();
};

std::ostream& operator<<(std::ostream& os, const Hammer& that);

#endif
