/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:07:01 by mazaid            #+#    #+#             */
/*   Updated: 2025/07/18 18:51:19 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Memory address of str      : " << &str << "\n";
	std::cout << "Memory address held by stringPTR   : " << stringPTR << "\n";
	std::cout << "Memory address held by stringREF   : " << &stringREF << "\n";

	std::cout << "Value of str               : " << str << "\n";
	std::cout << "Value pointed to by stringPTR      : " << *stringPTR << "\n";
	std::cout << "Value referenced by stringREF      : " << stringREF << "\n";

	return (0);
}

