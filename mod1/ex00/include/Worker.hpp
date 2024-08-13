/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:13:05 by adantas-          #+#    #+#             */
/*   Updated: 2024/08/12 18:48:03 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKER_HPP
# define WORKER_HPP
# include "Position.hpp"
# include "Statistic.hpp"
# include "ATool.hpp"
# include "Shovel.hpp"
# include "Hammer.hpp"
# include <map>
# include <vector>

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
	std::vector<Tool*> _tools;
	static std::map<Tool*, Worker*> _helper;

public:
	Worker();
	Worker(const Worker& that);
	Worker(Position pos, Statistic stat, std::vector<Tool*> tools);
	~Worker();

	Worker& operator=(const Worker& that);

	void removeTool(Tool* tool);
	void pickTool(Tool* tool);
	Position getCoordonnee() const;
	Position getCoordonnee();
	Statistic getStat() const;
	Statistic getStat();
	std::vector<Tool*> getTools() const;
	std::vector<Tool*> getTools();
};

std::ostream& operator<<(std::ostream& os, const Worker& that);

#endif
