/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graph.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:12:42 by adantas-          #+#    #+#             */
/*   Updated: 2024/08/06 17:04:30 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_HPP
# define GRAPH_HPP
# include "Vector2.hpp"
# include <vector>

class Graph
{
private:
	std::vector<Vector2> _vectors;
	std::pair< std::pair<int, int>, std::pair<int, int> > _size;

public:
	Graph(void);

	void addVector(const Vector2& vec2);
	void addVector(const float x, const float y);
	void renderPoints(void);
	std::vector<Vector2>::const_iterator begin(void) const { return this->_vectors.begin(); }
	std::vector<Vector2>::iterator begin(void) { return this->_vectors.begin(); }
	std::vector<Vector2>::const_iterator end(void) const { return this->_vectors.end(); }
	std::vector<Vector2>::iterator end(void) { return this->_vectors.end(); }
	std::pair< std::pair<int, int>, std::pair<int, int> > getSize(void) const { return this->_size; }
	std::pair< std::pair<int, int>, std::pair<int, int> > getSize(void) { return this->_size; }
	std::pair<int, int> getSizeX(void) const { return this->_size.first; }
	std::pair<int, int>	getSizeX(void) { return this->_size.first; }
	std::pair<int, int>	getSizeY(void) const { return this->_size.second; }
	std::pair<int, int>	getSizeY(void) { return this->_size.second; }
};

std::ostream& operator<<(std::ostream& os, const Graph& that);

#endif
