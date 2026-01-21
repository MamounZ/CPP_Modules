/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:44:53 by mazaid            #+#    #+#             */
/*   Updated: 2026/01/21 20:13:45 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <utility>
#include <cctype>
#include <stdexcept>
#include <cstdlib>

class PmergeMe
{
	private:
	std::vector<int> vec;
	std::deque<int> deq;
	std::vector<int> vecSorted;
	std::deque<int> deqSorted;
	double vecTime;
	double deqTime;

	// Ford-Johnson helpers for vector
	void fordJohnsonVec(std::vector<int> &arr);
	std::vector<size_t> generateJacobsthalOrder(size_t pendSize);
	size_t binarySearchVec(const std::vector<int> &arr, int value, size_t end);

	// Ford-Johnson helpers for deque
	void fordJohnsonDeq(std::deque<int> &arr);
	size_t binarySearchDeq(const std::deque<int> &arr, int value, size_t end);
		
	public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	void parseInput(int argc, char **argv);
	void sort();
	void displayResults();
};

#endif
