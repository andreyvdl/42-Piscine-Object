/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Workshop.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:30:21 by adantas-          #+#    #+#             */
/*   Updated: 2024/08/14 17:54:26 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKSHOP_HPP
# define WORKSHOP_HPP
# include <iostream>
# include "Worker.hpp"
# include <list>

/*
*	Associação é o ato de relacionar 2 clases com uma ou mais instancias.
*	Diferente da agregaçãa, na Associação uma classe pode ser criada unicamente
*		para trabalhar com outra.
*	Pense da seguinte forma: Um cliente está ciente da garçonete que o serviu e
*		a garçonete está ciente do cliente que ela serviu, a garçonete tem uma
*		Associação com esse cliente através do trabalho, porém a garçonete não
*		depende unicamente desse cliente e pode servir 0 ou mais clientes ao
*		mesmo tempo e vice-versa.
*	source: https://www.learncpp.com/cpp-tutorial/association/
*/
class Workshop
{
private:
	std::list<Worker*> _workers;

public:
	Workshop();
	Workshop(const Workshop& that);
	~Workshop();

	Workshop& operator=(const Workshop& that);

	void contract(Worker* worker);
	void fire(Worker* worker);
	void executeWorkDay();
	std::list<Worker*> getWorkers() const;
	std::list<Worker*> getWorkers();
};

std::ostream& operator<<(std::ostream& os, const Workshop& workshop);

#endif
