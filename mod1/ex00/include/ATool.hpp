/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATool.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:43:13 by adantas-          #+#    #+#             */
/*   Updated: 2024/08/13 11:13:51 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATOOL_HPP
# define ATOOL_HPP
# include <iostream>

class Tool
{
protected:
	size_t _numberOfUses;

public:
	Tool();
	Tool(size_t uses);
	virtual ~Tool() {};

	virtual void use() = 0;
	size_t getNbrOfUses() const;
	size_t getNbrOfUses();
};

std::ostream& operator<<(std::ostream& os, const Tool& that);

#endif
