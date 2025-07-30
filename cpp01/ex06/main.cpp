/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 22:02:23 by mazaid            #+#    #+#             */
/*   Updated: 2025/07/23 16:52:11 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl h;
	int index = 55;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	if (argc != 2)
		return (0);

	for (int i = 0; i < 4; i++)
	{
		if (argv[1] == levels[i])
			index = i;
	}

	switch (index)
	{
		case 0:
			std::cout << "[ DEBUG ]\n";
			h.complain("DEBUG");
		case 1:
			std::cout << "[ INFO ]\n";
			h.complain("INFO");
		case 2:
			std::cout << "[ WARNING ]\n";
			h.complain("WARNING");
		case 3:
			std::cout << "[ ERROR ]\n";
			h.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}

	return (0);
}