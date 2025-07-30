/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:24:57 by mazaid            #+#    #+#             */
/*   Updated: 2025/07/29 18:07:53 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	type = "ice";
	std::cout << "Ice's default constructors\n";
}

Ice::Ice(const Ice &other)
{
	*this = other;
	std::cout << "Ice's copy constructors\n";
}

Ice &Ice::operator=(const Ice &other)
{
	std::cout << "ice ===========\n";
	this->type = other.type;
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice is out!\n";
}

AMateria *Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}