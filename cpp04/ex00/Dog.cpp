/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 08:57:17 by mazaid            #+#    #+#             */
/*   Updated: 2025/07/28 09:11:51 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog's default constructors\n";
}

Dog::Dog(const Dog &other)
{
	*this = other;
	std::cout << "Dog's copy constructors\n";
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
		type = other.type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog is out\n";
}

void Dog::makeSound() const
{
	std::cout << "Dooooooooog\n";
}
