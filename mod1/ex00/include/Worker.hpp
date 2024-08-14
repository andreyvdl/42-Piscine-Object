/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:13:05 by adantas-          #+#    #+#             */
/*   Updated: 2024/08/14 17:33:30 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKER_HPP
# define WORKER_HPP
# include "Position.hpp"
# include "Statistic.hpp"
# include "ATool.hpp"
# include <map>
# include <vector>

class Workshop;

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
	bool _employed;
	std::vector<Tool*> _tools;
	std::vector<Workshop*> _workplaces;
	static std::map<Tool*, Worker*> _helper;

	friend class Workshop;

public:
	Worker();
	Worker(const Worker& that);
	Worker(
		Position pos,
		Statistic stat,
		std::vector<Tool*> tools,
		std::vector<Workshop*> workplaces
	);
	~Worker();

	Worker& operator=(const Worker& that);

	void removeTool(Tool* tool);
	void pickTool(Tool* tool);
	void throwCV(std::vector<Workshop*> workshops);
	void sendCV(Workshop* workshop);
	void giveup(Workshop* workshop);
	void work();
	Position getCoordonnee() const;
	Position getCoordonnee();
	Statistic getStat() const;
	Statistic getStat();
	bool getEmployed() const;
	bool getEmployed();
	std::vector<Tool*> getTools() const;
	std::vector<Tool*> getTools();
	std::vector<Workshop*> getWorkplaces() const;
	std::vector<Workshop*> getWorkplaces();
};

std::ostream& operator<<(std::ostream& os, const Worker& that);

#endif
