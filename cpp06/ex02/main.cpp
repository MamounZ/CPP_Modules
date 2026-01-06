/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:43:06 by mazaid            #+#    #+#             */
/*   Updated: 2026/01/06 17:55:17 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "identify.hpp"

int main()
{
	srand(time(NULL));
	
	Base* ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete ptr;

	A a;
	identify(a);

	return 0;
}
