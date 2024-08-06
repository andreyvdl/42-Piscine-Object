/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector2.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:49:47 by adantas-          #+#    #+#             */
/*   Updated: 2024/08/06 17:28:51 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2_HPP
# define VECTOR2_HPP
# include <iostream>

class Vector2
{
private:
	std::pair<float, float> _pos;

	Vector2(void);

public:
	Vector2(float x, float y);

	std::pair<float, float> getPosition(void) const { return this->_pos; };
	std::pair<float, float> getPosition(void) { return this->_pos; };
};

std::ostream& operator<<(std::ostream& os, const Vector2& that);

#endif
