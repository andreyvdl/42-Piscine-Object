/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:03:56 by adantas-          #+#    #+#             */
/*   Updated: 2024/08/08 16:22:05 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Worker.hpp"
#include <iostream>

int main()
{
	Shovel* pa = new Shovel(5);
	Worker bob;
	std::cout << "bob:" << std::endl << bob << std::endl;
	std::cout << " ----- " << std::endl << std::endl;
	Worker thomas(Position(42, 21, 10), Statistic(5, 1500), pa); 
	std::cout << "thomas:" << std::endl << thomas << std::endl;
	std::cout << " ----- " << std::endl << std::endl;
	pa.use();
	Worker john(thomas);
	std::cout << "john:" << std::endl << john << std::endl;
	std::cout << " ----- " << std::endl << std::endl;
	Worker zack(thomas);
	zack = bob;
	std::cout << "zack:" << std::endl << zack << std::endl;
}
