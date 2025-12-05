/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:43:06 by mazaid            #+#    #+#             */
/*   Updated: 2025/12/05 19:53:54 by mazaid           ###   ########.fr       */
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
