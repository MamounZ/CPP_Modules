/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 20:14:19 by mazaid            #+#    #+#             */
/*   Updated: 2025/07/19 16:41:44 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) {this->name = name; this->weapon = NULL;}
HumanB::~HumanB(){}
void HumanB::attack(void) const
{
	if(weapon)
		std::cout << name << " attacks with their " << weapon->getType() << "\n";
	else
		std::cout << name << " has no weapon!\n";
}
const Weapon *HumanB::getweapon(void) const { return (weapon);}
void HumanB::setWeapon(Weapon &weapon) { this->weapon = &weapon;}
const std::string &HumanB::getname(void) const {return (name);}
void HumanB::setname(std::string name) {this->name = name;}