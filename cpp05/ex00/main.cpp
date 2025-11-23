/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 20:02:39 by mazaid            #+#    #+#             */
/*   Updated: 2025/11/23 20:02:40 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "=== Test 1: Valid Bureaucrat Creation ===" << std::endl;
	try {
		Bureaucrat bob("Bob", 50);
		std::cout << bob << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\n=== Test 2: Grade Too High (0) ===" << std::endl;
	try {
		Bureaucrat invalid("Invalid", 0);
		std::cout << invalid << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << "\n=== Test 3: Grade Too Low (151) ===" << std::endl;
	try {
		Bureaucrat invalid("Invalid", 151);
		std::cout << invalid << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << "\n=== Test 4: Increment Grade ===" << std::endl;
	try {
		Bureaucrat alice("Alice", 2);
		std::cout << "Before increment: " << alice << std::endl;
		alice.incrementGrade();
		std::cout << "After increment: " << alice << std::endl;
		alice.incrementGrade(); // This should throw
		std::cout << "After second increment: " << alice << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << "\n=== Test 5: Decrement Grade ===" << std::endl;
	try {
		Bureaucrat charlie("Charlie", 149);
		std::cout << "Before decrement: " << charlie << std::endl;
		charlie.decrementGrade();
		std::cout << "After decrement: " << charlie << std::endl;
		charlie.decrementGrade(); // This should throw
		std::cout << "After second decrement: " << charlie << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << "\n=== Test 6: Copy Constructor ===" << std::endl;
	try {
		Bureaucrat original("Original", 75);
		Bureaucrat copy(original);
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy: " << copy << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\n=== Test 7: Assignment Operator ===" << std::endl;
	try {
		Bureaucrat first("First", 100);
		Bureaucrat second("Second", 50);
		std::cout << "Before assignment:" << std::endl;
		std::cout << "First: " << first << std::endl;
		std::cout << "Second: " << second << std::endl;
		first = second;
		std::cout << "After assignment (first = second):" << std::endl;
		std::cout << "First: " << first << std::endl;
		std::cout << "Second: " << second << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\n=== Test 8: Default Constructor ===" << std::endl;
	try {
		Bureaucrat defaultBureaucrat;
		std::cout << defaultBureaucrat << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
