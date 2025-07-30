/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:07:00 by mazaid            #+#    #+#             */
/*   Updated: 2025/07/29 18:07:16 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	name = "";
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	for (int i = 0; i < 500; i++)
		Mdropped[i] = NULL;
	std::cout << "Character's default constructors\n";
}

Character::Character(const std::string &name)
{
	this->name = name;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	for (int i = 0; i < 500; i++)
		Mdropped[i] = NULL;
	std::cout << "Character's parametarized constructors\n";
}

Character::Character(const Character &other)
{
	*this = other;
	std::cout << "Character's copy constructors\n";
}

Character &Character::operator=(const Character &other)
{
	if (this !=& other)
	{
		name = other.name;
		for (int i = 0; i < 4; i++)
		{
			delete inventory[i];
			inventory[i] = other.inventory[i]->clone();
		}
		for (int i = 0; i < 500; i++)
		{
			delete Mdropped[i];
			Mdropped[i] = other.Mdropped[i]->clone();
		}
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete inventory[i];
	}
	for (int i = 0; i < 500; i++)
	{
		if (Mdropped[i])
			delete Mdropped[i];
	}
	std::cout << "Character is out!\n";
}

std::string const &Character::getName() const
{
	return (name);
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = m->clone();
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	for (int i = 0; i < 500; i++)
	{
		if (!Mdropped[i])
		{
			Mdropped[i] = inventory[idx];
			break;
		}
	}
	if (idx >= 0 && idx < 4)
		inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && inventory[idx])
		inventory[idx]->use(target);
}

void Character::printInvintory()
{
	std::cout << "Invintory is:-----------------------\n";
	for (int i = 0; i < 4 ; i++)
	{
		if (inventory[i])
			std::cout << inventory[i]->getType() << "\n";
	}
}
