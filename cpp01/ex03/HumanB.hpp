/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 20:11:56 by mazaid            #+#    #+#             */
/*   Updated: 2025/07/19 16:41:55 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
private:
	Weapon *weapon;
	std::string name;

public:
	HumanB(std::string name);
	~HumanB();
	void attack(void) const;
	const Weapon *getweapon(void) const;
	void setWeapon(Weapon &weapon);
	const std::string &getname(void) const;
	void setname(std::string name);
};

#endif