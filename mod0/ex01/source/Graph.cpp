/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graph.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:32:27 by adantas-          #+#    #+#             */
/*   Updated: 2024/08/06 17:32:35 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Graph.hpp"
#include <algorithm>
#include <cstring>
#include <iostream>
#include <utility>
#include <cassert>
#include <vector>

bool compX(const Vector2& a, const Vector2& b)
{
	std::pair<float, float> av = a.getPosition(), bv = b.getPosition();
	return av.first < bv.first;
}

bool compY(const Vector2& a, const Vector2& b)
{
	std::pair<float, float> av = a.getPosition(), bv = b.getPosition();
	return av.second < bv.second;
}

Graph::Graph(void): _vectors(std::vector<Vector2>()),
	_size(std::pair< std::pair<int, int>, std::pair<int, int> >()) {}

void Graph::addVector(const Vector2& vec2)
{
	this->_vectors.push_back(vec2);
}

void Graph::addVector(const float x, const float y)
{
	this->_vectors.push_back(Vector2(x, y));
}

static void thereIsAVec(std::vector<Vector2>& vecs, int x, int y, bool lastCol)
{
	for (std::vector<Vector2>::iterator it = vecs.begin(); it != vecs.end(); it++) {
		if (int(it->getPosition().first) == x && int(it->getPosition().second) == y) {
			std::cout << (lastCol ? "X" : "X ");
			return;
		}

	}

	std::cout << (lastCol ? "." : ". ");
}

void Graph::renderPoints(void)
{
	std::vector<Vector2>::iterator	minX = std::min_element(this->_vectors.begin(), this->_vectors.end(), compX);
	std::vector<Vector2>::iterator	maxX = std::max_element(this->_vectors.begin(), this->_vectors.end(), compX);
	std::vector<Vector2>::iterator	minY = std::min_element(this->_vectors.begin(), this->_vectors.end(), compY);
	std::vector<Vector2>::iterator	maxY = std::max_element(this->_vectors.begin(), this->_vectors.end(), compY);
	std::pair<int, int>	x = std::make_pair(minX->getPosition().first, maxX->getPosition().first);
	std::pair<int, int>	y = std::make_pair(minY->getPosition().second, maxY->getPosition().second);
	this->_size = std::make_pair(x, y);
	for (int i = this->_size.second.second; i >= this->_size.second.first; i--) {
		std::cout << ">& " << i << " ";
		for (int j = this->_size.first.first; j <= this->_size.first.second; j++)
			thereIsAVec(this->_vectors, j, i, j == this->_size.first.second);

		std::cout << std::endl;
	}

	std::cout << ">&   ";
	for (int j = this->_size.first.first; j <= this->_size.first.second; j++)
	  std::cout << j << (j == this->_size.first.second ? "" : " "); 

	std::cout << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Graph& that)
{
	os << "Vectors inside the graph:" << std::endl;
	for (std::vector<Vector2>::const_iterator it = that.begin(); it != that.end(); it++)
		os << *it << std::endl;

	return os;
}
