/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shovel.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:06:53 by adantas-          #+#    #+#             */
/*   Updated: 2024/08/12 18:02:40 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOVEL_HPP
# define SHOVEL_HPP
# include <iostream>
# include "ATool.hpp"

/*
*	Agregação tem certa relação com composição, porém na agregação um objeto
*		não possui sua existencia atrelada a uma outra classe;
*	Na composição Pos e Stat eram independentes e o Worker dependia deles a
*		ponto de controlar o tempo de vida de ambos, aqui Shovel é
*		independente, mas Worker não controla seu tempo de vida, Shovel pode
*		continuar fora de Worker mesmo após ser atribuido a um;
*	Pense em células no seu sangue, mesmo após essas células serem extraidas
*		elas vivem fora de você, ainda que tenha sido parte de você, você não
*		controla o tempo de vida delas.
*	source: https://www.learncpp.com/cpp-tutorial/aggregation/
*/
class Shovel: public Tool
{
public:
	Shovel();
	Shovel(const Shovel& that);
	Shovel(const size_t uses);
	~Shovel();

	Shovel& operator=(const Shovel& that);

	void use();
};

std::ostream& operator<<(std::ostream& os, const Shovel& that);

#endif
