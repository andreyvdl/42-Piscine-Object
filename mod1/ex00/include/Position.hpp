/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Position.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:31:04 by adantas-          #+#    #+#             */
/*   Updated: 2024/08/08 13:30:59 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POSITION_HPP
# define POSITION_HPP
# include <iostream>

class Position
{
private:
	int _x, _y, _z;

public:
	Position();
	Position(const int x, const int y, const int z);
	Position(const Position& that);
	~Position();

	Position& operator=(const Position& that);

	int getX() const;
	int getX();
	int getY() const;
	int getY();
	int getZ() const;
	int getZ();
};

std::ostream& operator<<(std::ostream& os, const Position& that);

#endif
