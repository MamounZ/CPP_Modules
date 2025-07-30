/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:59:44 by mazaid            #+#    #+#             */
/*   Updated: 2025/07/19 16:09:37 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA
{
	private:
	Weapon &weapon;
	std::string name;

	public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void attack(void) const;
	const Weapon &getweapon(void) const;
	const std::string &getname(void) const;
	void setname(std::string name);
};

#endif