/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Workshop.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:36:39 by adantas-          #+#    #+#             */
/*   Updated: 2024/08/13 16:03:15 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Workshop.hpp"
#include <sstream>
#include <algorithm>

Workshop::Workshop():
_workers(std::list<Worker*>())
{
	std::cerr << "Workshop created!" << std::endl;
}

Workshop::Workshop(const Workshop& that):
_workers(std::list<Worker*>())
{
	std::cerr << "Workshop copied!" << std::endl;
	*this = that;
}

Workshop::~Workshop()
{
	std::cerr << "Workshop destroyed!" << std::endl;
}

Workshop& Workshop::operator=(const Workshop& that)
{
	std::cerr << "Workshop =operator!" << std::endl;
	if (this != &that)
		this->_workers = that._workers;

	return *this;
}

void Workshop::contract(Worker* worker)
{
	std::cerr << "Workshop contracting worker!" << std::endl;
	std::list<Worker*>::iterator it = std::find(this->_workers.begin(), this->_workers.end(), worker);
	if (it == this->_workers.end()) {
		std::cerr << "Welcome " << worker << "!" << std::endl;
		this->_workers.push_back(worker);
		this->_workers.sort();
	}

	else
		std::cerr << "Worker already contracted!" << std::endl;
}

void Workshop::fire(Worker* worker)
{
	std::cerr << "Workshop firing worker!" << std::endl;
	std::list<Worker*>::iterator it = std::find(this->_workers.begin(), this->_workers.end(), worker);
	if (it != this->_workers.end()) {
		std::cerr << "Goodbye " << worker << "!" << std::endl;
		this->_workers.erase(it);
		this->_workers.sort();
	}

	else
		std::cerr << "You don't work here!" << std::endl;
}

void Workshop::executeWorkDay()
{
	std::cerr << "Workshop executing work day!" << std::endl;
	for (std::list<Worker*>::iterator it = this->_workers.begin(); it != this->_workers.end(); it++)
		(*it)->work();
}

std::list<Worker*> Workshop::getWorkers() const
{
	std::cerr << "Workshop const getting workers!" << std::endl;
	return this->_workers;
}

std::list<Worker*> Workshop::getWorkers()
{
	std::cerr << "Workshop getting workers!" << std::endl;
	return this->_workers;
}

std::ostream& operator<<(std::ostream& os, const Workshop& workshop)
{
	std::cerr << "Workshop <<operator!" << std::endl;
	std::stringstream ss;
	ss << "Workshop workers:" << std::endl;
	std::list<Worker*> workers = workshop.getWorkers();
	for (std::list<Worker*>::const_iterator it = workers.begin(); it != workers.end(); it++)
		ss << **it << std::endl;

	os << ss.str();
	return os;
}
