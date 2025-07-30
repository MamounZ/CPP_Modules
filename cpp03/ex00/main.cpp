/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:43:03 by mazaid            #+#    #+#             */
/*   Updated: 2025/07/26 13:44:25 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	std::cout << "\n--- Construction Tests ---\n";
	ClapTrap a("Alpha");
	ClapTrap b("Beta");
	ClapTrap c(a);
	ClapTrap d;
	d = b;

	std::cout << "\n--- Attack Tests ---\n";
	a.attack("Beta");
	for (int i = 0; i < 10; ++i)
		a.attack("Target");
	a.attack("OutOfEnergyTarget");

	std::cout << "\n--- Damage Tests ---\n";
	b.takeDamage(4);
	b.takeDamage(10);
	b.attack("Target");
	b.beRepaired(5);

	std::cout << "\n--- Repair Tests ---\n";
	c.beRepaired(3);
	for (int i = 0; i < 9; ++i)
		c.beRepaired(1);
	c.beRepaired(5);

	std::cout << "\n--- Destruction Order ---\n";
	return 0;
}
