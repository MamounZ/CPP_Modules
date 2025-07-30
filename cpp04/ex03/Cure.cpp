/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:38:50 by mazaid            #+#    #+#             */
/*   Updated: 2025/07/29 18:07:42 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	type = "cure";
	std::cout << "Cure's default constructors\n";
}

Cure::Cure(const Cure &other)
{
	*this = other;
	std::cout << "Cure's copy constructors\n";
}

Cure &Cure::operator=(const Cure &other)
{
	std::cout << "cure ===========\n";
	this->type = other.type;
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure is out!\n";
}

AMateria *Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}