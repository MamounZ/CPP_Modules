/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 08:20:15 by mazaid            #+#    #+#             */
/*   Updated: 2025/07/29 11:59:25 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const int size = 10;
	Animal *animals[size];
	Dog *a = new Dog();
	Dog *b = new Dog();

	// Fill the array
	for (int i = 0; i < size / 2; ++i)
		animals[i] = new Dog();
	for (int i = size / 2; i < size; ++i)
		animals[i] = new Cat();

	std::cout << "\n---- Testing Polymorphic Behavior ----" << std::endl;
	for (int i = 0; i < size; ++i)
		animals[i]->makeSound();

	std::cout << "\n---- Deleting Animals ----" << std::endl;
	for (int i = 0; i < size; ++i)
		delete animals[i];

	std::cout << "\n---- Testing Deep Copy for dog ----" << std::endl;
	// Dog originalDog;
	// originalDog.setIdea(0, "Chase the mailman");
	a->setIdea(0, "Chase the mailman");
	// Dog copyDog = originalDog; // Should call the copy constructor
	*b = *a;
	// std::cout << "Original Dog Idea: " << originalDog.getIdea(0) << std::endl;
	// std::cout << "Copied Dog Idea:   " << copyDog.getIdea(0) << std::endl;

	std::cout << "Original Dog Idea: " << a->getIdea(0) << std::endl;
	std::cout << "Copied Dog Idea:   " << b->getIdea(0) << std::endl;
	// originalDog.setIdea(0, "Dig holes");
	a->setIdea(0, "Dig holes");
	std::cout << "\nAfter modifying original:\n";
	std::cout << "Original Dog Idea: " << a->getIdea(0) << std::endl;
	std::cout << "Copied Dog Idea:   " << b->getIdea(0) << std::endl;
	// std::cout << "Original Dog Idea: " << originalDog.getIdea(0) << std::endl;
	// std::cout << "Copied Dog Idea:   " << copyDog.getIdea(0) << std::endl;

	std::cout << "\n---- Testing Deep Copy for cat ----" << std::endl;
	Cat originalCat;
	originalCat.setIdea(0, "Play with rop");
	Cat copyCat = originalCat; // Should call the copy constructor

	std::cout << "Original Cat Idea: " << originalCat.getIdea(0) << std::endl;
	std::cout << "Copied Cat Idea:   " << copyCat.getIdea(0) << std::endl;

	originalCat.setIdea(0, "Drink milk");
	std::cout << "\nAfter modifying original:\n";
	std::cout << "Original Cat Idea: " << originalCat.getIdea(0) << std::endl;
	std::cout << "Copied Cat Idea:   " << copyCat.getIdea(0) << std::endl;
	delete a;
	delete b;
	return 0;
}