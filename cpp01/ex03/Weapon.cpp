/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:50:10 by mazaid            #+#    #+#             */
/*   Updated: 2025/07/19 16:48:36 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) {this->type = type;}
Weapon::~Weapon() {}
const std::string &Weapon::getType() const {return (type);}
void Weapon::setType(std::string type) {this->type = type;}