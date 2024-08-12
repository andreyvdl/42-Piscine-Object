/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:13:05 by adantas-          #+#    #+#             */
/*   Updated: 2024/08/12 11:28:25 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKER_HPP
# define WORKER_HPP
# include "Position.hpp"
# include "Statistic.hpp"
# include "Shovel.hpp"
# include <map>

/*
*	Composição é o ato de construir coisas complexas com coisas simples;
*	A classe Worker deve ter uma Position e Status (Statistics);
*	Então primeiro a gente constrói esses dois antes de contruir o Worker;
*	Perceba que, o Worker NÃO herda os atributos deles.
*	Pense da seguinte maneira: seu corpo é complexo, mas composto de coisas
*		simples, como mãos, pernas, etc.
*	source: https://www.learncpp.com/cpp-tutorial/composition/
*/
class Worker
{
private:
	Position _coordonnee;
	Statistic _stat;
	Shovel* _shovel;
	static std::map<Shovel*, Worker*> _helper;

public:
	Worker();
	Worker(const Worker& that);
	Worker(Position pos, Statistic stat, Shovel* shovel);
	~Worker();

	Worker& operator=(const Worker& that);

	void removeShovel(Shovel* shovel);
	void pickShovel(Shovel* shovel);
	Position getCoordonnee() const;
	Position getCoordonnee();
	Statistic getStat() const;
	Statistic getStat();
	Shovel* getShovel() const;
	Shovel* getShovel();
};

std::ostream& operator<<(std::ostream& os, const Worker& that);

#endif
