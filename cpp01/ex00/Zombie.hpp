/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:57:59 by mazaid            #+#    #+#             */
/*   Updated: 2025/07/16 23:04:19 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

class Zombie
{
	private:
	std::string name;

	public:
	Zombie();
	~Zombie();
	void setname(std::string name);
	std::string getname();
	void announce(void);
};
Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif