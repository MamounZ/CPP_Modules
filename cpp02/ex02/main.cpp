/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:13:57 by mazaid            #+#    #+#             */
/*   Updated: 2025/07/24 21:18:41 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << Fixed(7) / Fixed(3) << std::endl;
	std::cout << 6/4.0 << '\n';
	return 0;
}

// int main()
// {
// 	// Constructors
// 	Fixed a;		 // Default constructor
// 	Fixed b(10);	 // Int constructor
// 	Fixed c(42.42f); // Float constructor
// 	Fixed d(b);		 // Copy constructor

// 	// Assignment
// 	a = Fixed(5.05f); // Assignment operator

// 	std::cout << "\n--- Output values ---" << std::endl;
// 	std::cout << "a: " << a << std::endl;
// 	std::cout << "b: " << b << std::endl;
// 	std::cout << "c: " << c << std::endl;
// 	std::cout << "d: " << d << std::endl;

// 	std::cout << "\n--- Comparison operators ---" << std::endl;
// 	std::cout << "a > b: " << (a > b) << std::endl;
// 	std::cout << "a < b: " << (a < b) << std::endl;
// 	std::cout << "a >= b: " << (a >= b) << std::endl;
// 	std::cout << "a <= b: " << (a <= b) << std::endl;
// 	std::cout << "a == b: " << (a == b) << std::endl;
// 	std::cout << "a != b: " << (a != b) << std::endl;

// 	std::cout << "\n--- Arithmetic operators ---" << std::endl;
// 	std::cout << "a + b: " << (a + b) << std::endl;
// 	std::cout << "a - b: " << (a - b) << std::endl;
// 	std::cout << "a * b: " << (a * b) << std::endl;
// 	std::cout << "b / a: " << (b / a) << std::endl;
// 	std::cout << "a / b: " << (a / b) << std::endl;

// 	std::cout << "\n--- Increment / Decrement ---" << std::endl;
// 	Fixed e;
// 	std::cout << "e: " << e << std::endl;
// 	std::cout << "++e: " << ++e << std::endl;
// 	std::cout << "e: " << e << std::endl;
// 	std::cout << "e++: " << e++ << std::endl;
// 	std::cout << "e: " << e << std::endl;
// 	std::cout << "--e: " << --e << std::endl;
// 	std::cout << "e--: " << e-- << std::endl;
// 	std::cout << "e: " << e << std::endl;

// 	std::cout << "\n--- Min / Max ---" << std::endl;
// 	Fixed &minRef = Fixed::min(a, b);
// 	const Fixed &maxRef = Fixed::max(c, d);
// 	std::cout << "min(a, b): " << minRef << std::endl;
// 	std::cout << "max(c, d): " << maxRef << std::endl;

// 	std::cout << "\n--- Conversion functions ---" << std::endl;
// 	std::cout << "a.toInt(): " << a.toInt() << std::endl;
// 	std::cout << "c.toFloat(): " << c.toFloat() << std::endl;

// 	return 0;
// }