/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:43:03 by mazaid            #+#    #+#             */
/*   Updated: 2025/07/26 22:28:53 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	std::cout << "== Default constructor test ==\n";
	DiamondTrap d1;
	d1.whoAmI();
	d1.attack("Target1");
	d1.takeDamage(10);
	d1.beRepaired(5);

	std::cout << "\n== Parameterized constructor test ==\n";
	DiamondTrap d2("Serena");
	d2.whoAmI();
	d2.attack("Target2");
	d2.takeDamage(30);
	d2.beRepaired(15);

	std::cout << "\n== Copy constructor test ==\n";
	DiamondTrap d3(d2);
	d3.whoAmI();
	d3.attack("Target3");

	std::cout << "\n== Assignment operator test ==\n";
	DiamondTrap d4;
	d4 = d2;
	d4.whoAmI();


	std::cout << "\n== Zero HP edge case test ==\n";
	d4.takeDamage(100);	  // Should reduce HP to 0
	d4.attack("Someone"); // Should not be able to attack
	d4.beRepaired(10);	  // Should repair if logic allows

	std::cout << "\n== Zero EP edge case test ==\n";
	DiamondTrap d5("NoEnergy");
	for (int i = 0; i < 60; i++)
	{
		d5.attack("Drain"); // Should stop when EP = 0
	}

	std::cout << "\n== Destructor test ==\n";
	// All destructors will be triggered at the end
	return 0;
}
