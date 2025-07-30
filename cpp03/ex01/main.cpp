/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:43:03 by mazaid            #+#    #+#             */
/*   Updated: 2025/07/26 17:21:24 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	std::cout << "\n--- Default constructor ---\n";
	ScavTrap defaultTrap;
	defaultTrap.guardGate();

	std::cout << "\n--- Parameterized constructor ---\n";
	ScavTrap john("John");
	john.guardGate();

	std::cout << "\n--- Copy constructor ---\n";
	ScavTrap clone(john);
	clone.setname("Clone");
	clone.guardGate();

	std::cout << "\n--- Assignment operator ---\n";
	ScavTrap assigned;
	assigned = john;
	assigned.setname("Assigned");
	assigned.guardGate();

	std::cout << "\n--- Attack test ---\n";
	john.attack("a target");
	for (int i = 0; i < 55; i++)
	{
		john.attack("SpamTarget"); // This should eventually say "no energy"
	}

	std::cout << "\n--- Repair test ---\n";
	john.beRepaired(10); // Should fail due to 0 energy

	std::cout << "\n--- Take Damage test ---\n";
	john.takeDamage(20);
	john.takeDamage(999); // Overkill

	std::cout << "\n--- Repair after damage ---\n";
	john.beRepaired(10); // Should still fail due to 0 EP

	std::cout << "\n--- Self-assignment check ---\n";
	john.guardGate();

	std::cout << "\n--- Destructors will now run automatically ---\n";
	return 0;
}