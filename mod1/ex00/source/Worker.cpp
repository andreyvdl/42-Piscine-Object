/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:51:10 by adantas-          #+#    #+#             */
/*   Updated: 2024/08/14 15:51:15 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Worker.hpp"
#include "../include/Workshop.hpp"
#include <sstream>

std::map<Tool*, Worker*> Worker::_helper = std::map<Tool*, Worker*>();


Worker::Worker():
_coordonnee(Position()),
_stat(Statistic()),
_employed(false),
_tools(std::vector<Tool*>()),
_workplaces(std::vector<Workshop*>())
{
#ifdef DEBUG
	std::cerr << "New Worker created!" << std::endl;
#endif
}

Worker::Worker(const Worker& that):
_coordonnee(Position()),
_stat(Statistic()),
_employed(false),
_tools(std::vector<Tool*>()),
_workplaces(std::vector<Workshop*>())
{
#ifdef DEBUG
	std::cerr << "New Worker copied!" << std::endl;
#endif
	*this = that;
}

Worker::Worker(
	Position pos,
	Statistic stat,
	std::vector<Tool*> tools,
	std::vector<Workshop*> workplaces
):
_coordonnee(pos), _stat(stat), _employed(false)
{
#ifdef DEBUG
	std::cerr << "New Worker with values!" << std::endl;
#endif
	for (std::vector<Tool*>::iterator it = tools.begin(); it != tools.end(); ++it)
		this->pickTool(*it);

	for (std::vector<Workshop*>::iterator it = workplaces.begin(); it != workplaces.end(); ++it)
		(*it)->contract(this);

	if (this->_workplaces.size() != 0)
		this->_employed = true;
}

Worker::~Worker()
{
#ifdef DEBUG
	std::cerr << "Worker deleted!" << std::endl;
#endif
}

Worker& Worker::operator=(const Worker& that)
{
#ifdef DEBUG
	std::cerr << "Worker =operator!" << std::endl;
#endif
	if (this != &that) {
		this->_coordonnee = that._coordonnee;
		this->_stat = that._stat;
		for (size_t i = 0; i < that._tools.size(); i++)
			this->pickTool(that._tools[i]);

		for (size_t i = 0; i < that._workplaces.size(); i++)
			that._workplaces[i]->contract(this);
	
		if (this->_workplaces.size() != 0)
			this->_employed = true;
	}

	return *this;
}

void Worker::pickTool(Tool* tool)
{
	if (tool == NULL) {
		std::cerr << "No tool to pickup!" << std::endl;
		return;
	}

	std::map<Tool*, Worker*>::iterator it = this->_helper.find(tool);
	if (it == this->_helper.end()) {
		std::cerr << "Tool picked!" << std::endl;
		this->_helper.insert(std::pair<Tool*, Worker*>(tool, this));
		this->_tools.push_back(tool);
	}

	else {
		std::cerr << "Hey bro, i need this tool!" << std::endl;
		it->second->removeTool(tool);
		this->_helper.insert(std::pair<Tool*, Worker*>(tool, this));
		this->_tools.push_back(tool);
	}

}

void Worker::removeTool(Tool* tool)
{
	std::cerr << "Tool removed!" << std::endl;
	this->_helper.erase(tool);
	for (std::vector<Tool*>::iterator it = this->_tools.begin(); it != this->_tools.end(); ++it) {
		if (*it == tool) {
			this->_tools.erase(it);
			break;
		}
	}
}

void Worker::throwCV(std::vector<Workshop*> workshops)
{
	std::cerr << "PLEASE I NEED TO FEED THE KIDS!" << std::endl;
	for (size_t i = 0; i < workshops.size(); i++)
		workshops[i]->contract(this);

	if (this->_workplaces.size() != 0)
		this->_employed = true;
}

void Worker::sendCV(Workshop* workshop)
{
	std::cerr << "Could you please sign my CLT!" << std::endl;
	workshop->contract(this);
	if (this->_workplaces.size() != 0)
		this->_employed = true;
}

void Worker::giveup(Workshop* workshop)
{
	std::cerr << "F THIS JOB!" << std::endl;
	workshop->fire(this);
	if (this->_workplaces.size() == 0)
		this->_employed = false;
}

void Worker::work()
{
	std::cerr <<
		"I am " << this << ", and I'm digging a hole/Diggy diggy hole, diggy diggy hole"
		<< std::endl;
	if (this->_employed) {
		for (size_t i = 0; i < this->_tools.size(); i++)
			this->_tools[i]->use();

	}
}

std::vector<Tool*> Worker::getTools() const
{
#ifdef DEBUG
	std::cerr << "Worker const tool getter!" << std::endl;
#endif
	return this->_tools;
}

std::vector<Tool*> Worker::getTools()
{
#ifdef DEBUG
	std::cerr << "Worker tool getter!" << std::endl;
#endif
	return this->_tools;
}

Position Worker::getCoordonnee() const
{
#ifdef DEBUG
	std::cerr << "Worker const coordonnee getter!" << std::endl;
#endif
	return this->_coordonnee;
}

Position Worker::getCoordonnee()
{
#ifdef DEBUG
	std::cerr << "Worker coordonnee getter!" << std::endl;
#endif
	return this->_coordonnee;
}

Statistic Worker::getStat() const
{
#ifdef DEBUG
	std::cerr << "Worker const stat getter!" << std::endl;
#endif
	return this->_stat;
}

Statistic Worker::getStat()
{
#ifdef DEBUG
	std::cerr << "Worker stat getter!" << std::endl;
#endif
	return this->_stat;
}

bool Worker::getEmployed() const
{
#ifdef DEBUG
	std::cerr << "Worker const employed getter!" << std::endl;
#endif
	return this->_employed;
}

bool Worker::getEmployed()
{
#ifdef DEBUG
	std::cerr << "Worker employed getter!" << std::endl;
#endif
	return this->_employed;
}

std::vector<Workshop*> Worker::getWorkplaces() const
{
#ifdef DEBUG
	std::cerr << "Worker const workplaces getter!" << std::endl;
#endif
	return this->_workplaces;
}

std::vector<Workshop*> Worker::getWorkplaces()
{
#ifdef DEBUG
	std::cerr << "Worker worgetter!" << std::endl;
#endif
	return this->_workplaces;
}

std::ostream& operator<<(std::ostream& os, const Worker& that)
{
	std::stringstream ss;
#ifdef DEBUG
	std::cerr << "Worker <<operator!" << std::endl;
#endif
	ss << "Worker attributes:" << std::endl;
	ss << "Coordonee: " << that.getCoordonnee() << "Stat: " << that.getStat()
		<< "Tools: ";
	for (size_t i = 0; i < that.getTools().size(); ++i)
		ss << that.getTools()[i] << " | " << *(that.getTools()[i]);

	ss << "Work at: " << std::endl;
	for (size_t i = 0; i < that.getWorkplaces().size(); i++)
		ss << that.getWorkplaces()[i] << std::endl;

	os << ss.str();
	return os;
}
