/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 12:32:51 by mazaid            #+#    #+#             */
/*   Updated: 2025/07/26 17:07:59 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	name = "";
	hit_point = 10;
	energy_points = 10;
	attack_damage = 0;
	std::cout << "[Default constructor] A new ClapTrap was created!\n";
}
ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	hit_point = 10;
	energy_points = 10;
	attack_damage = 0;
	std::cout << "[Constructor] A new ClapTrap named " << name << " was created!\n";
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	std::cout << "[Copy constructor] A new ClapTrap named " << other.name << " was created!\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		name = other.name;
		hit_point = other.hit_point;
		energy_points = other.energy_points;
		attack_damage = other.attack_damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << ", is out!\n";
}
void ClapTrap::attack(const std::string &target)
{
	if (energy_points > 0 && hit_point > 0)
	{
		std::cout << "ClapTrap " << name << " attacks "<< target <<", causing " << attack_damage << " points of damage!\n";
		energy_points--;
	}
	else
		std::cout << "ClapTrap " << name << " has no energy or is dead and can't attack!\n";
}
void ClapTrap::takeDamage(unsigned int amount)
{
	int old_hit_point = hit_point;
	hit_point -= amount;
	if (hit_point < 0)
	{
		std::cout << "ClapTrap " << name << " took " << old_hit_point << ", amount of damage\n";
		hit_point = 0;
	}
	else
		std::cout << "ClapTrap " << name << " took " << amount << ", amount of damage\n";
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (energy_points > 0 && hit_point > 0)
	{
		std::cout << "ClapTrap " << name << " gained " << amount << ", amount of hit point\n";
		hit_point += amount;
		energy_points--;
	}
	else
		std::cout << "ClapTrap " << name << " has no energy or is dead and can't repaire itself!\n";
}

void ClapTrap::setname(std::string name)
{
	this->name = name;
}

void ClapTrap::sethp(int hp)
{
	this->hit_point = hp;
}

void ClapTrap::setep(int ep)
{
	this->energy_points = ep;
}

void ClapTrap::setad(int ad)
{
	this->attack_damage = ad;
}

// Getters
std::string ClapTrap::getname() const
{
	return (name);
}

int ClapTrap::gethp() const
{
	return (hit_point);
}

int ClapTrap::getep() const
{
	return (energy_points);
}

int ClapTrap::getad() const
{
	return (attack_damage);
}