/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 08:20:15 by mazaid            #+#    #+#             */
/*   Updated: 2025/07/29 11:45:54 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const int size = 4;
	AAnimal *animals[size];
	// A_Animal aasdasd;
	std::cout << "---- Creating Animals ----" << std::endl;
	for (int i = 0; i < size; ++i)
	{
		if (i < size / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	std::cout << "\n---- Animal Sounds ----" << std::endl;
	for (int i = 0; i < size; ++i)
	{
		animals[i]->makeSound();
	}
	std::cout << "\n---- Deleting Animals ----" << std::endl;
	for (int i = 0; i < size; ++i)
	{
		delete animals[i];
	}
	// std::cout << "\n---- Testing Deep Copy ----" << std::endl;
	// Dog originalDog;
	// originalDog.setIdea(0, "Chase the cat");
	// Dog copiedDog = originalDog;
	// std::cout << "Original Dog's idea: " << originalDog.getIdea(0) << std::endl;
	// std::cout << "Copied Dog's idea:   " << copiedDog.getIdea(0) << std::endl;
	// originalDog.setIdea(0, "Bark at the postman");
	// std::cout << "Original Dog's idea: " << originalDog.getIdea(0) << std::endl;
	// std::cout << "Copied Dog's idea:   " << copiedDog.getIdea(0) << std::endl;
	return 0;
}