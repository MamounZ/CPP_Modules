/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:23:36 by mazaid            #+#    #+#             */
/*   Updated: 2025/12/09 20:30:36 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	Array<int> a(5);
	for (unsigned int i = 0; i < a.size(); ++i)
		a[i] = i * 10;

	Array<int> b = a;

	std::cout << "a: ";
	for (unsigned int i = 0; i < a.size(); ++i)
		std::cout << a[i] << " ";
	std::cout << "\n";

	std::cout << "b: ";
	for (unsigned int i = 0; i < b.size(); ++i)
		std::cout << b[i] << " ";
	std::cout << "\n";

	try
	{
		std::cout << a[10] << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
