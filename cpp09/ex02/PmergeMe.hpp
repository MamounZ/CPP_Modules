/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:44:53 by mazaid            #+#    #+#             */
/*   Updated: 2026/02/09 20:51:48 by mazaid           ###   ########.fr       */
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
#include <sys/time.h>

class PmergeMe
{
private:
	std::vector<int> originalSequence;
	std::vector<int> vctr;
	std::deque<int> dque;
	std::vector<int> recVctr(std::vector<int> vectoor);
	std::deque<int> recDque(std::deque<int> dequee);
	double vctrTime;
	double dqueTime;

public:
	PmergeMe();
	PmergeMe(const std::vector<int>& vctr, const std::deque<int>& dque, const std::vector<int>& originalSequence);
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	void sortContainers();
	void displayContainers(std::clock_t ParsingTime);
	bool vctr_is_sorted();
	bool dque_is_sorted();
};
std::vector<int> jacobsthal(int n);
std::vector<int> generateInsertionIndices(size_t size);

#endif
