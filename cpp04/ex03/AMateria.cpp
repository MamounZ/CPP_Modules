/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:51:24 by mazaid            #+#    #+#             */
/*   Updated: 2025/07/29 18:06:41 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	type = "";
	std::cout << "AMateria's default constructors\n";
}

AMateria::AMateria(std::string const &type)
{
	this->type = type;
	std::cout << "AMateria's parametarized constructors\n";
}

AMateria::AMateria(const AMateria &other)
{
	*this = other;
	std::cout << "AMateria's copy constructors\n";
}

AMateria &AMateria::operator=(const AMateria &other)
{
	(void)other;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria is out!\n";
}

std::string const &AMateria::getType() const
{
	return (type);
}

void AMateria::setType(const std::string type)
{
	this->type = type;
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}
