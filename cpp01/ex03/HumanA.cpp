/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 19:54:47 by mazaid            #+#    #+#             */
/*   Updated: 2025/07/26 16:42:24 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon) {this->name = name;}
HumanA::~HumanA(){}
void HumanA::attack(void) const {std::cout << getname() << " attacks with their " << weapon.getType() << "\n";}
const Weapon &HumanA::getweapon(void) const {return (weapon);}
const std::string &HumanA::getname(void) const {return (name);}
void HumanA::setname(std::string name){this->name = name;}