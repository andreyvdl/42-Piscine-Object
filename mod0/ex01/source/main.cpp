/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:49:15 by adantas-          #+#    #+#             */
/*   Updated: 2024/08/06 16:19:04 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Graph.hpp"
#include <ostream>

int main(void)
{
	Vector2 vec(4.2f, 2.4f);
	std::cout << vec << std::endl;

	Graph g;
	g.addVector(vec);
	g.addVector(-1.1f, +0.9f);
	std::cout << g << std::endl;

	g.renderPoints();
}
