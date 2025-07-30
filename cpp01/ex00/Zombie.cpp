/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 20:10:42 by mazaid            #+#    #+#             */
/*   Updated: 2025/07/16 23:11:20 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){name = "";}
Zombie::~Zombie(){std::cout << "Zombie " << name << " has died!!\n";}

void Zombie::setname(std::string name){this->name = name;}
std::string Zombie::getname(void) {return (name);}

void Zombie::announce(void) { std::cout << getname() << ": BraiiiiiiinnnzzzZ...\n"; }