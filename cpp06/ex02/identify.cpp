/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:22:05 by mazaid            #+#    #+#             */
/*   Updated: 2026/01/06 17:59:53 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "identify.hpp"

Base * generate(void)
{
	switch (rand() % 3)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
	}
	return NULL;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "A" << std::endl;
		return;
	}

	if (dynamic_cast<B*>(p))
	{
		std::cout << "B" << std::endl;
		return;
	}

	if (dynamic_cast<C*>(p))
	{
		std::cout << "C" << std::endl;
		return;
	}
}

void identify(Base& p)
{
	try
	{
		void(dynamic_cast<A&>(p));
		std::cout << "A" << std::endl;
	} catch (...) {}
	
	try
	{
		void(dynamic_cast<B&>(p));
		std::cout << "B" << std::endl;
	} catch (...) {}

	try
	{
		void(dynamic_cast<C&>(p));
		std::cout << "C" << std::endl;
	} catch (...) {}
}
