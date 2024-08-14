/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:03:56 by adantas-          #+#    #+#             */
/*   Updated: 2024/08/14 17:03:36 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Worker.hpp"
#include "../include/Hammer.hpp"
#include "../include/Shovel.hpp"
#include "../include/Workshop.hpp"
#include <iostream>

int main()
{
	std::vector<Workshop*> works;
	works.push_back(new Workshop);
	works.push_back(new Workshop);

	std::vector<Tool*> tools; 
	tools.push_back(new Shovel(5));
	tools.push_back(new Hammer(3));

	Hammer* martelo = new Hammer(10);
	Shovel* pa = new Shovel(1);

	Worker bob;
	std::cout << "bob:" << std::endl << bob << std::endl;
	std::cout << " ----- " << std::endl << std::endl;

	Worker thomas(Position(42, 21, 10), Statistic(5, 1500), tools, works);
	std::cout << "thomas:" << std::endl << thomas << std::endl;
	std::cout << " ----- " << std::endl << std::endl;

	Worker john(thomas);
	john.pickTool(martelo);
	std::cout << "john:" << std::endl << john << std::endl;
	std::cout << " ----- " << std::endl << std::endl;

	Worker zack(thomas);
	zack.pickTool(pa);
	zack = bob;
	std::cout << "zack:" << std::endl << zack << std::endl;

	works[0]->executeWorkDay();
	works[1]->executeWorkDay();
}
