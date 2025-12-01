/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 20:24:57 by mazaid            #+#    #+#             */
/*   Updated: 2025/11/25 15:35:03 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Test 1: Create Forms and Bureaucrats ===" << std::endl;
	try {
		Bureaucrat bob("Bob", 50);
		Form formA("FormA", 100, 50);

		std::cout << bob << std::endl;
		std::cout << formA << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: Successful Signing ===" << std::endl;
	try {
		Bureaucrat alice("Alice", 20);
		Form permit("Permit", 50, 25);

		std::cout << permit << std::endl;
		alice.signForm(permit);
		std::cout << permit << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: Failed Signing (Grade Too Low) ===" << std::endl;
	try {
		Bureaucrat intern("Intern", 100);
		Form topSecret("TopSecret", 10, 5);

		std::cout << topSecret << std::endl;
		intern.signForm(topSecret);
		std::cout << topSecret << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Invalid Form Creation ===" << std::endl;
	try {
		Form invalid("Invalid", 0, 50);
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}
