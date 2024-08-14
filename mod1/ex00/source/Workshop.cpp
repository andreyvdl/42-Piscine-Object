/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Workshop.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:36:39 by adantas-          #+#    #+#             */
/*   Updated: 2024/08/14 16:15:09 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Workshop.hpp"
#include <sstream>
#include <algorithm>

Workshop::Workshop():
_workers(std::list<Worker*>())
{
#ifdef DEBUG
	std::cerr << "Workshop created!" << std::endl;
#endif
}

Workshop::Workshop(const Workshop& that):
_workers(std::list<Worker*>())
{
#ifdef DEBUG
	std::cerr << "Workshop copied!" << std::endl;
#endif
	*this = that;
}

Workshop::~Workshop()
{
#ifdef DEBUG
	std::cerr << "Workshop destroyed!" << std::endl;
#endif
}

Workshop& Workshop::operator=(const Workshop& that)
{
#ifdef DEBUG
	std::cerr << "Workshop =operator!" << std::endl;
#endif
	if (this != &that) {
		for (std::list<Worker*>::const_iterator it = that._workers.begin(); it != that._workers.end(); it++)
			this->contract(*it);

	}

	return *this;
}

void Workshop::contract(Worker* worker)
{
#ifdef DEBUG
	std::cerr << "Workshop contracting worker!" << std::endl;
#endif
	std::list<Worker*>::iterator it = std::find(this->_workers.begin(), this->_workers.end(), worker);
	if (it == this->_workers.end()) {
		std::cerr << "Welcome " << worker << "!" << std::endl;
		this->_workers.push_back(worker);
		this->_workers.sort();
		worker->_workplaces.push_back(this);
	}

	else
		std::cerr << "Worker already contracted!" << std::endl;
}

void Workshop::fire(Worker* worker)
{
#ifdef DEBUG
	std::cerr << "Workshop firing worker!" << std::endl;
#endif
	std::list<Worker*>::iterator it = std::find(this->_workers.begin(), this->_workers.end(), worker);
	if (it != this->_workers.end()) {
		std::cerr << "Goodbye " << worker << "!" << std::endl;
		this->_workers.erase(it);
		this->_workers.sort();
		std::vector<Workshop*>::iterator it2;
		it2 = std::find(worker->_workplaces.begin(), worker->_workplaces.end(), this);
		worker->_workplaces.erase(it2);
	}

	else
		std::cerr << "You don't work here!" << std::endl;
}

void Workshop::executeWorkDay()
{
#ifdef DEBUG
	std::cerr << "Workshop executing work day with " << this->_workers.size() << " workers!" << std::endl;
#endif
	for (std::list<Worker*>::iterator it = this->_workers.begin(); it != this->_workers.end(); it++)
		(*it)->work();
}

std::list<Worker*> Workshop::getWorkers() const
{
#ifdef DEBUG
	std::cerr << "Workshop const getting workers!" << std::endl;
#endif
	return this->_workers;
}

std::list<Worker*> Workshop::getWorkers()
{
#ifdef DEBUG
	std::cerr << "Workshop getting workers!" << std::endl;
#endif
	return this->_workers;
}

std::ostream& operator<<(std::ostream& os, const Workshop& workshop)
{
#ifdef DEBUG
	std::cerr << "Workshop <<operator!" << std::endl;
#endif
	std::stringstream ss;
	ss << "Workshop workers:" << std::endl;
	std::list<Worker*> workers = workshop.getWorkers();
	for (std::list<Worker*>::const_iterator it = workers.begin(); it != workers.end(); it++)
		ss << **it << std::endl;

	os << ss.str();
	return os;
}
