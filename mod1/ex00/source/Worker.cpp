/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:51:10 by adantas-          #+#    #+#             */
/*   Updated: 2024/08/13 12:35:28 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Worker.hpp"
#include <sstream>

std::map<Tool*, Worker*> Worker::_helper = std::map<Tool*, Worker*>();

Worker::Worker():
_coordonnee(Position()), _stat(Statistic()), _tools(std::vector<Tool*>())
{
	// std::cerr << "New Worker created!" << std::endl;
}

Worker::Worker(const Worker& that):
_coordonnee(Position()), _stat(Statistic()), _tools(std::vector<Tool*>())
{
	// std::cerr << "New Worker copied!" << std::endl;
	*this = that;
}

Worker::Worker(Position pos, Statistic stat, std::vector<Tool*> tools):
_coordonnee(pos), _stat(stat)
{
	// std::cerr << "New Worker with values!" << std::endl;
	for (std::vector<Tool*>::iterator it = tools.begin(); it != tools.end(); ++it)
		this->pickTool(*it);
}

Worker::~Worker()
{
	// std::cerr << "Worker deleted!" << std::endl;
}

Worker& Worker::operator=(const Worker& that)
{
	// std::cerr << "Worker =operator!" << std::endl;
	if (this != &that) {
		this->_coordonnee = that._coordonnee;
		this->_stat = that._stat;
		for (size_t i = 0; i < that._tools.size(); i++)
			this->pickTool(that._tools[i]);
	}

	return *this;
}

void Worker::pickTool(Tool* tool)
{
	if (tool == NULL) {
		// std::cerr << "No tool to pickup!" << std::endl;
		return;
	}

	std::map<Tool*, Worker*>::iterator it = this->_helper.find(tool);
	if (it == this->_helper.end()) {
		// std::cerr << "Tool picked!" << std::endl;
		this->_helper.insert(std::pair<Tool*, Worker*>(tool, this));
		this->_tools.push_back(tool);
	}

	else {
		// std::cerr << "Hey bro, i need this tool!" << std::endl;
		it->second->removeTool(tool);
		this->_helper.insert(std::pair<Tool*, Worker*>(tool, this));
		this->_tools.push_back(tool);
	}

}

void Worker::removeTool(Tool* tool)
{
	// std::cerr << "Tool removed!" << std::endl;
	this->_helper.erase(tool);
	for (std::vector<Tool*>::iterator it = this->_tools.begin(); it != this->_tools.end(); ++it) {
		if (*it == tool) {
			this->_tools.erase(it);
			break;
		}
	}
}

std::vector<Tool*> Worker::getTools() const
{
	// std::cerr << "Worker const tool getter!" << std::endl;
	return this->_tools;
}

std::vector<Tool*> Worker::getTools()
{
	// std::cerr << "Worker tool getter!" << std::endl;
	return this->_tools;
}

Position Worker::getCoordonnee() const
{
	// std::cerr << "Worker const coordonnee getter!" << std::endl;
	return this->_coordonnee;
}

Position Worker::getCoordonnee()
{
	// std::cerr << "Worker coordonnee getter!" << std::endl;
	return this->_coordonnee;
}

Statistic Worker::getStat() const
{
	// std::cerr << "Worker const stat getter!" << std::endl;
	return this->_stat;
}

Statistic Worker::getStat()
{
	// std::cerr << "Worker stat getter!" << std::endl;
	return this->_stat;
}

std::ostream& operator<<(std::ostream& os, const Worker& that)
{
	std::stringstream ss;
	// std::cerr << "Worker <<operator!" << std::endl;
	ss << "Worker attributes:" << std::endl;
	ss << "Coordonee: " << that.getCoordonnee() << "Stat: " << that.getStat()
		<< "Tools: ";
	for (size_t i = 0; i < that.getTools().size(); ++i)
		ss << &that.getTools()[i] << " | " << *(that.getTools()[i]);

	os << ss.str();
	return os;
}
