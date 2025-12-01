/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 20:24:57 by mazaid            #+#    #+#             */
/*   Updated: 2025/12/01 14:06:32 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Test 1: Create Shrubbery Form ===" << std::endl;
	{
		Intern someRandomIntern;
		AForm* form;

		form = someRandomIntern.makeForm("shrubbery creation", "home");
		if (form)
		{
			std::cout << *form << std::endl;

			Bureaucrat bob("Bob", 137);
			bob.signForm(*form);
			bob.executeForm(*form);

			delete form;
		}
	}

	std::cout << "\n=== Test 2: Create Robotomy Form ===" << std::endl;
	{
		Intern someRandomIntern;
		AForm* form;

		form = someRandomIntern.makeForm("robotomy request", "Bender");
		if (form)
		{
			std::cout << *form << std::endl;

			Bureaucrat alice("Alice", 1);
			alice.signForm(*form);
			alice.executeForm(*form);

			delete form;
		}
	}

	std::cout << "\n=== Test 3: Create Presidential Form ===" << std::endl;
	{
		Intern someRandomIntern;
		AForm* form;

		form = someRandomIntern.makeForm("presidential pardon", "Arthur");
		if (form)
		{
			std::cout << *form << std::endl;

			Bureaucrat president("President", 1);
			president.signForm(*form);
			president.executeForm(*form);

			delete form;
		}
	}

	std::cout << "\n=== Test 4: Unknown Form ===" << std::endl;
	{
		Intern someRandomIntern;
		AForm* form;

		form = someRandomIntern.makeForm("unknown form", "target");
		if (form)
		{
			std::cout << *form << std::endl;
			delete form;
		}
		else
		{
			std::cout << "Form creation failed (returned NULL)" << std::endl;
		}
	}

	std::cout << "\n=== Test 5: Multiple Forms ===" << std::endl;
	{
		Intern intern;
		Bureaucrat boss("Boss", 1);
		AForm* forms[3];

		forms[0] = intern.makeForm("shrubbery creation", "garden");
		forms[1] = intern.makeForm("robotomy request", "Criminal");
		forms[2] = intern.makeForm("presidential pardon", "Ford");

		for (int i = 0; i < 3; i++)
		{
			if (forms[i])
			{
				boss.signForm(*forms[i]);
				boss.executeForm(*forms[i]);
				delete forms[i];
			}
		}
	}

	return 0;
}
