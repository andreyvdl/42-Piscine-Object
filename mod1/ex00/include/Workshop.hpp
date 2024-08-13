/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Workshop.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:30:21 by adantas-          #+#    #+#             */
/*   Updated: 2024/08/13 15:35:53 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKSHOP_HPP
# define WORKSHOP_HPP
# include <iostream>
# include "Worker.hpp"
# include <list>

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