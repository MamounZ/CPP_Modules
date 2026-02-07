/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:44:53 by mazaid            #+#    #+#             */
/*   Updated: 2026/02/07 23:01:15 by mazaid           ###   ########.fr       */
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


class PmergeMe
{
private:
	std::vector<int> vctr;
	std::deque<int> dque;
	std::vector<int> recVctr(std::vector<int> vectoor);

public:
	PmergeMe();
	PmergeMe(const std::vector<int>& vctr, const std::deque<int>& dque);
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	void sortVector();
	void sortDeque();
	void displayContainers();
};

#endif
