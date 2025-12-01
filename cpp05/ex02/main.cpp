/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 20:24:57 by mazaid            #+#    #+#             */
/*   Updated: 2025/11/25 17:09:43 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "=== Test 1: ShrubberyCreationForm ===" << std::endl;
	try {
		Bureaucrat bob("Bob", 137);
		ShrubberyCreationForm shrub("home");

		std::cout << shrub << std::endl;
		bob.signForm(shrub);
		bob.executeForm(shrub);
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: RobotomyRequestForm ===" << std::endl;
	try {
		Bureaucrat alice("Alice", 45);
		RobotomyRequestForm robot("Bender");

		std::cout << robot << std::endl;
		alice.signForm(robot);
		alice.executeForm(robot);
		alice.executeForm(robot); // Try again for different result
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: PresidentialPardonForm ===" << std::endl;
	try {
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardon("Arthur Dent");

		std::cout << pardon << std::endl;
		president.signForm(pardon);
		president.executeForm(pardon);
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Execute Without Signing ===" << std::endl;
	try {
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm form("garden");

		boss.executeForm(form); // Should fail - not signed
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: Insufficient Grade to Execute ===" << std::endl;
	try {
		Bureaucrat intern("Intern", 150);
		Bureaucrat manager("Manager", 50);
		PresidentialPardonForm pardon("Criminal");

		manager.signForm(pardon);
		intern.executeForm(pardon); // Should fail - grade too low
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}
