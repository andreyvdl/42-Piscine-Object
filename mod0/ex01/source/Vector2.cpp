/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector2.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:09:50 by adantas-          #+#    #+#             */
/*   Updated: 2024/08/07 17:02:43 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Vector2.hpp"
#include <utility>

Vector2::Vector2(float x, float y)
{
	if (x < 0.0f || y < 0.0f) {
		x = (x < 0.0f ? 0 : x);
		y = (y < 0.0f ? 0 : y);
	}
	this->_pos = std::make_pair(x, y);
}
std::ostream& operator<<(std::ostream& os, const Vector2& that)
{
	std::pair<float, float> pair = that.getPosition();
	os << "X: " << pair.first << " Y: " << pair.second;
	return (os);
}
