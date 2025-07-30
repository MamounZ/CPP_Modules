/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:43:03 by mazaid            #+#    #+#             */
/*   Updated: 2025/07/26 17:55:45 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	std::cout << "=== Creating FragTrap A ===\n";
	FragTrap a("A");

	std::cout << "\n=== Creating FragTrap B (copy of A) ===\n";
	FragTrap b(a);

	std::cout << "\n=== Creating FragTrap C (default) ===\n";
	FragTrap c;

	std::cout << "\n=== Assigning FragTrap A to C ===\n";
	c = a;

	std::cout << "\n=== Testing attack (with energy) ===\n";
	a.attack("Target1");

	std::cout << "\n=== Testing takeDamage ===\n";
	a.takeDamage(20);
	std::cout << "HP after 20 damage: " << a.gethp() << "\n";

	std::cout << "\n=== Testing repair (with energy) ===\n";
	a.beRepaired(10);
	std::cout << "HP after repairing 10: " << a.gethp() << "\n";

	std::cout << "\n=== Testing attack until energy depletes ===\n";
	while (a.getep() > 0)
		a.attack("EnergyDrain");

	std::cout << "\n=== Try to attack with 0 energy ===\n";
	a.attack("NoEnergyTarget");

	std::cout << "\n=== Try to repair with 0 energy ===\n";
	a.beRepaired(5);

	std::cout << "\n=== Bring HP to 0 and test behaviors ===\n";
	a.takeDamage(a.gethp());
	a.attack("DeadTarget");
	a.beRepaired(10);
	a.highFivesGuys();

	std::cout << "\n=== Testing highFivesGuys on alive FragTrap ===\n";
	b.highFivesGuys();

	std::cout << "\n=== Destroying all FragTraps ===\n";
	return 0;
}
