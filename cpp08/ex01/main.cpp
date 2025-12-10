/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:27:33 by mazaid            #+#    #+#             */
/*   Updated: 2025/12/10 22:01:33 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <vector>

int main()
{
	// Test basic functionality
	Span sp(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(16);
	sp.addNumber(2);

	std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl; // 1
	std::cout << "longestSpan:  " << sp.longestSpan() << std::endl;	 // 15

	// Test addRange with vector
	std::vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(5);
	numbers.push_back(10);
	numbers.push_back(15);
	numbers.push_back(20);
	Span sp2(10);
	sp2.addRange(numbers.begin(), numbers.end());

	std::cout << "addRange shortest: " << sp2.shortestSpan() << std::endl; // 4
	std::cout << "addRange longest:  " << sp2.longestSpan() << std::endl;  // 19

	// Test 10,000 numbers with addRange
	std::cout << "\n=== Testing 10,000 numbers ===" << std::endl;
	const unsigned int N = 10000;
	std::vector<int> big_numbers(N);

	for (unsigned int i = 0; i < N; ++i)
		big_numbers[i] = (i % 1000) + (i % 100);

	Span sp_big(N);
	sp_big.addRange(big_numbers.begin(), big_numbers.end());

	std::cout << "10K numbers - shortestSpan: " << sp_big.shortestSpan() << std::endl;
	std::cout << "10K numbers - longestSpan:  " << sp_big.longestSpan() << std::endl;

	// Test capacity limit
	Span sp3(3);
	sp3.addRange(numbers.begin(), numbers.begin() + 3); // 1,5,10

	try
	{
		sp3.addNumber(25); // Should throw
	}
	catch (std::exception const &e)
	{
		std::cout << "✓ " << e.what() << std::endl;
	}

	return 0;
}
