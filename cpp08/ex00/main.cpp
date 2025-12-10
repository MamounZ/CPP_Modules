/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:41:26 by mazaid            #+#    #+#             */
/*   Updated: 2025/12/10 18:14:15 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
	std::vector <int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	try
	{
		std::vector<int>::iterator it = easyfind(v, 0);
		std::cout << "num "<< *it <<" was found\n";
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);
	lst.push_back(5);
	lst.push_back(6);

	try
	{
		std::list<int>::iterator it = easyfind(lst, 5);
		std::cout << "num " << *it << " was found\n";
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << '\n';
	}

	return (0);
}