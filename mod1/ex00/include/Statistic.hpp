/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Statistic.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:53:49 by adantas-          #+#    #+#             */
/*   Updated: 2024/08/08 13:31:23 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATISTIC_HPP
# define STATISTIC_HPP
# include <iostream>

class Statistic
{
private:
	int _level;
	int _exp;

public:
	Statistic();
	Statistic(const Statistic& that);
	Statistic(const int level, const int exp);
	~Statistic();

	Statistic& operator=(const Statistic& that);

	int getLevel() const;
	int getLevel();
	int getExp() const;
	int getExp();
};

std::ostream& operator<<(std::ostream& os, const Statistic& that);

#endif
