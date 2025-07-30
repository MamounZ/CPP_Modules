/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:18:13 by mazaid            #+#    #+#             */
/*   Updated: 2025/07/26 22:45:29 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap()
{
	this->_name = "";
	this->setname("_clap_name");
	this->sethp(100);
	this->setep(50);
	this->setad(30);
	std::cout << "[Default constructor] A new DiamondTrap was created!\n";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name)
{
	this->_name = name;
	this->setname(name + "_clap_name");
	this->sethp(100);
	this->setep(50);
	this->setad(30);
	std::cout << "[Constructor] A new DiamondTrap named " << this->_name << " was created!\n";
}
DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other)
{
	this->_name = other._name;
	std::cout << "[Copy constructor] A new DiamondTrap named " << other.ClapTrap::getname() << " was created!\n";
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		ClapTrap::operator=(other);
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << getname() << ", is out!\n";
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name is " << _name << "\n";
	std::cout << "ClapTrap name is " << ClapTrap::getname() << "\n";
}
