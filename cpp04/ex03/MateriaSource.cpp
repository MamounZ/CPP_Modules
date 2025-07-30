/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 22:56:33 by mazaid            #+#    #+#             */
/*   Updated: 2025/07/29 18:08:42 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"

int MateriaSource::Mcount = 0;

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		materias[i] = NULL ;
	}
	std::cout << "MateriaSource's default constructors\n";
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	*this = other;
	std::cout << "MateriaSource's copy constructors\n";
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << "equal opppp************************************\n";
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			delete materias[i];
			materias[i] = other.materias[i]->clone();
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource is out!\n";
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!materias[i])
		{
			materias[i] = m;
			break;
		}
	}
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
	if (Mcount < 500)
	{
		for (int i = 0; i < 4; i++)
		{
			if (materias[i] && materias[i]->getType() == type)
			{
				Mcount++;
				return materias[i]->clone();
			}
		}
	}
	else
		std::cout << "You Have reached the maximum amount of materias!!!!!\n";
	return NULL;
}

void MateriaSource::printMateria()
{
	std::cout << "Materias are:-----------------------\n";
	for (int i = 0; i < 4; i++)
	{
		if (materias[i])
			std::cout << materias[i]->getType() << "\n";
	}
}
