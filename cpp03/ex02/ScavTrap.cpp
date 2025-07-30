/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:55:58 by mazaid            #+#    #+#             */
/*   Updated: 2025/07/26 21:58:50 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->setname("");
	this->sethp(100);
	this->setep(50);
	this->setad(20);
	std::cout << "[Default constructor] A new ScavTrap was created!\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->sethp(100);
	this->setep(50);
	this->setad(20);
	std::cout << "[Constructor] A new ScavTrap named " << getname() << " was created!\n";
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "[Copy constructor] A new ScavTrap named " << other.getname() << " was created!\n";
}

ScavTrap &ScavTrap::operator = (const ScavTrap &other)
{
	if (this != &other)
	{
		this->setname(other.getname());
		this->sethp(other.gethp());
		this->setep(other.getep());
		this->setad(other.getad());
	}
	return(*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << getname() << ", is out!\n";
}
void ScavTrap::attack(const std::string &target)
{
	if (getep() > 0 && gethp() > 0)
	{
		std::cout << "ScavTrap " << getname() << " attacks " << target << ", causing " << getad() << " points of damage!\n";
		setep(getep() - 1);
	}
	else
		std::cout << "ScavTrap " << getname() << " has no energy or is dead and can't attack!\n";
}
void ScavTrap::guardGate()
{
	if (gethp() > 0)
		std::cout << "ScavTrap named " << getname() << " is now in Gate keeper mode.\n";
	else
		std::cout << "ScavTrap " << getname() << " is dead and can't enter Gate keeper mode!\n ";
}
