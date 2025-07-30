/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 08:42:27 by mazaid            #+#    #+#             */
/*   Updated: 2025/07/28 09:11:42 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	type = "Animal";
	std::cout << "Animal's default constructors\n";
}

Animal::Animal(const Animal &other)
{
	*this = other;
	std::cout << "Animal's copy constructors\n";
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
		type = other.type;
	return(*this);
}

Animal::~Animal()
{
	std::cout << "Animal is out\n";
}

void Animal::makeSound() const
{
	std::cout << "Aniaaaaaaml\n";
}

std::string Animal::getType() const
{
	return (type);
}
