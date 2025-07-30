/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:34:42 by mazaid            #+#    #+#             */
/*   Updated: 2025/07/26 17:53:35 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->setname("");
	this->sethp(100);
	this->setep(100);
	this->setad(30);
	std::cout << "[Default constructor] A new FragTrap was created!\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->sethp(100);
	this->setep(100);
	this->setad(30);
	std::cout << "[Constructor] A new FragTrap named " << getname() << " was created!\n";
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "[Copy constructor] A new FragTrap named " << other.getname() << " was created!\n";
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		this->setname(other.getname());
		this->sethp(other.gethp());
		this->setep(other.getep());
		this->setad(other.getad());
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << getname() << ", is out!\n";
}
void FragTrap::highFivesGuys()
{
	if (gethp() > 0)
		std::cout << "FragTrap named " << getname() << " requests a positive high five! 🙌\n";
	else
		std::cout << "FragTrap " << getname() << " is dead and can't requests a positive high five!\n";
}