/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 08:53:18 by mazaid            #+#    #+#             */
/*   Updated: 2025/07/28 09:11:58 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << "Cat's default constructors\n";
}

Cat::Cat(const Cat &other)
{
	*this = other;
	std::cout << "Cat's copy constructors\n";
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
		type = other.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat is out\n";
}

void Cat::makeSound() const
{
	std::cout << "Caaaaaaaaat\n";
}
