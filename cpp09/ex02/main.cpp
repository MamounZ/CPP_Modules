/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:43:20 by mazaid            #+#    #+#             */
/*   Updated: 2026/02/07 23:22:03 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"
#include <climits>
#include <cstring>


int myIsNotDigit(char *input)
{
	for (size_t i = 0; i < std::strlen(input); i++)
	{
		if (!std::isdigit(input[i]))
		{
			std::cerr << "Error: Invalid input. Only positive integers are allowed.\n";
			return(1);
		}
	}
	return(0);
}
int isOverflow(char *input)
{
	if (std::strlen(input) == 0  || std::strlen(input) > 10)
	{
		std::cerr << "Error: Empty input or input too long.\n";
		return(1);
	}
	long num = std::atol(input);
	if (num > INT_MAX)
	{
		std::cerr << "Error: Integer overflow. Input exceeds the maximum allowed value.\n";
		return(1);
	}
	if(num <= 0)
	{
		std::cerr << "Error: Zero and negative numbers are not allowed.\n";
		return(1);
	}
	return(0);
}

int validateInput(char *input)
{
	if (myIsNotDigit(input))
		return(1);
	if (isOverflow(input))
		return(1);
	return(0);
}
void printContainers(const std::vector<int>& vctr, const std::deque<int>& dque)
{
	for(size_t i = 0; i < vctr.size(); i++)
		std::cout << "vector["<< i << "]: " << vctr[i] << " ";
	std::cout << std::endl;
	for(size_t i = 0; i < dque.size(); i++)
		std::cout << "deque["<< i << "]: " << dque[i] << " ";
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	std::vector<int>vctr;
	std::deque<int>dque;
	if (argc < 2)
	{
		std::cerr << "Error: No input provided.\n";
		return 1;
	}

	for (int i = 1; i < argc; i++)
	{
		if (validateInput(argv[i]))
			return 1;
		vctr.push_back(std::atoi(argv[i]));
		dque.push_back(std::atoi(argv[i]));
	}
	printContainers(vctr, dque);
	PmergeMe pmergeMe(vctr, dque);
	pmergeMe.sortVector();
	pmergeMe.displayContainers();
	return 0;
}
