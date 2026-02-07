/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:55:18 by mazaid            #+#    #+#             */
/*   Updated: 2026/02/07 23:27:56 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <cstddef>
#include <vector>

PmergeMe::PmergeMe()
{
    vctr.clear();
    dque.clear();
}
PmergeMe::PmergeMe(const std::vector<int>& vctr, const std::deque<int>& dque)
{
    this->vctr = vctr;
    this->dque = dque;
}
PmergeMe::PmergeMe(const PmergeMe& other)
{
    this->vctr = other.vctr;
    this->dque = other.dque;
}
PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        this->vctr = other.vctr;
        this->dque = other.dque;
    }
    return *this;
}
PmergeMe::~PmergeMe()
{
}

void PmergeMe::displayContainers()
{
    std::cout << "Vector: ";
    for (size_t i = 0; i < vctr.size(); i++)
    {
        std::cout << vctr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Deque: ";
    for (size_t i = 0; i < dque.size(); i++)
    {
        std::cout << dque[i] << " ";
    }
    std::cout << std::endl;
}
int jacobsthal(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    int prev2 = 0, prev1 = 1;
    for (int i = 2; i <= n; i++) {
        int curr = prev1 + 2 * prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

std::vector<int> generateInsertionIndices(size_t size)
{
	std::vector<int> jacob;
	int previos = 0;
	int k = 3;

	while (jacob.size() < size)
	{
		int current = jacobsthal(k);
		int target = std::min(current - 1, static_cast<int>(size) - 1);
		while(target >= previos)
		{
			if(std::find(jacob.begin(), jacob.end(), target) == jacob.end())
				jacob.push_back(target);
			target--;
		}
		previos = current;
		k++;
	}
	return jacob;
}

std::vector<int> PmergeMe::recVctr(std::vector<int> vectoor)
{
	int lastElement = 0;
	bool hasLastElement = false;
	if (vectoor.size() <= 1)
		return vectoor;
	if(vectoor.size() % 2 != 0)
	{
		lastElement = vectoor.back();
		vectoor.pop_back();
		hasLastElement = true;
	}
	std::vector<int> mainChain;
	std::vector<int> pendingChain;

	for(size_t i = 0; i < vectoor.size(); i += 2)
	{
		if(vectoor[i] > vectoor[i + 1])
		{
			mainChain.push_back(vectoor[i]);
			pendingChain.push_back(vectoor[i + 1]);
		}
		else
		{
			mainChain.push_back(vectoor[i + 1]);
			pendingChain.push_back(vectoor[i]);
		}
	}
	std::vector<int> newMainChain = recVctr(mainChain);
	std::vector<int> newPendingChain;
	for(size_t i = 0; i < newMainChain.size(); i++)
	{
		size_t oldindex = std::find(mainChain.begin(), mainChain.end(), newMainChain[i]) - mainChain.begin();
		newPendingChain.push_back(pendingChain[oldindex]);
	}
	newMainChain.insert(newMainChain.begin(), newPendingChain[0]);
	newPendingChain.erase(newPendingChain.begin());
	std::vector<int> insertionIndices = generateInsertionIndices(newPendingChain.size());
	for(size_t i = 0; i < insertionIndices.size();i++)
	{
		int value = newPendingChain[insertionIndices[i]];
		std::vector<int>::iterator it = std::lower_bound(newMainChain.begin(), newMainChain.end(), value);
		newMainChain.insert(it, value);
	}
	if (hasLastElement)
	{
		std::vector<int>::iterator it = std::lower_bound(newMainChain.begin(), newMainChain.end(), lastElement);
		newMainChain.insert(it, lastElement);
	}
	return newMainChain;
}

void PmergeMe::sortVector()
{
	this->vctr = recVctr(this->vctr);
}

