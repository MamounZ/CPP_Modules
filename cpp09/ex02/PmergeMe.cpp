/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:55:18 by mazaid            #+#    #+#             */
/*   Updated: 2026/02/10 16:05:12 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <cstddef>
#include <vector>
#include <iomanip>
#include <sys/time.h>

PmergeMe::PmergeMe()
{
    vctr.clear();
    dque.clear();
}
PmergeMe::PmergeMe(const std::vector<int>& vctr, const std::deque<int>& dque, const std::vector<int>& originalSequence)
{
    this->vctr = vctr;
    this->dque = dque;
	this->originalSequence = originalSequence;
}
PmergeMe::PmergeMe(const PmergeMe& other)
{
    this->vctr = other.vctr;
    this->dque = other.dque;
	this->originalSequence = other.originalSequence;
}
PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        this->vctr = other.vctr;
        this->dque = other.dque;
		this->originalSequence = other.originalSequence;
    }
    return *this;
}
PmergeMe::~PmergeMe()
{
}

void PmergeMe::displayContainers(std::clock_t ParsingTime)
{
	(void) ParsingTime;
	std::cout << "Before: ";
    for (size_t i = 0; i < originalSequence.size(); i++)
    {
        std::cout << originalSequence[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "After:  ";
    for (size_t i = 0; i < vctr.size(); i++)
    {
        std::cout << vctr[i] << " ";
    }
    std::cout << std::endl;
	if (vctr_is_sorted())
		std::cout << "Time to process a range of " << vctr.size() << " elements with std::vector : " << std::fixed << std::setprecision(6) << (ParsingTime + vctrTime) / 1000000.0 << " Seconds" << std::endl;
	if (dque_is_sorted())
		std::cout << "Time to process a range of " << dque.size() << " elements with std::deque : " << std::fixed << std::setprecision(6) << (ParsingTime + dqueTime) / 1000000.0 << " Seconds" << std::endl;
}


std::vector<int> jacobsthal(int n)
{
	std::vector<int> jacob;
    int prev2 = 0;
	int prev1 = 1;

	for (int i = 2; i <= n; i++)
	{
        int curr = prev1 + 2 * prev2;
		if (curr > 1)
			jacob.push_back(curr);
        prev2 = prev1;
        prev1 = curr;
    }
    return jacob;
}


std::vector<int> generateInsertionIndices(size_t size)
{
	// Generate Jacobsthal numbers until we exceed the size
	int current;
	int previos = 1;
	std::vector<int> initjacob = jacobsthal(size);
	std::vector<int> jacob;
	std::vector<int>::iterator it = std::lower_bound(initjacob.begin(), initjacob.end(), static_cast<int>(size));
	for (std::vector<int>::iterator iter = initjacob.begin(); iter != it; ++iter)
	{
		current = *iter;
		jacob.push_back(current - 1);
		while (--current > previos)
		{
			jacob.push_back(current - 1);
		}
		previos = *iter;
	}
	// If the last Jacobsthal number is less than the size, continue generating until we exceed the size
	if (jacob.size() + 1 < size)
	{
		current = size;
		jacob.push_back(current - 1);
		while (--current > previos)
		{
			jacob.push_back(current - 1);
		}
		previos = size;
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

	for(size_t i = 0; i < vectoor.size(); i += 2) 																// Process pairs of elements in the input vector
	{
		if(vectoor[i] > vectoor[i + 1]) 																		// store the larger element in the main chain and the smaller element in the pending chain
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
	for(size_t i = 0; i < newMainChain.size(); i++) 															// Reconstruct pending chain based on the order of the new main chain (to maintain the correct pairs)
	{
		size_t oldindex = std::find(mainChain.begin(), mainChain.end(), newMainChain[i]) - mainChain.begin();
		newPendingChain.push_back(pendingChain[oldindex]);
	}
	if (hasLastElement)
		newPendingChain.push_back(lastElement); 																// If there was an odd element, add it to the pending chain
			
	std::vector<int> finalMainChain = newMainChain; 															// Start with the new main chain as the base for the final sorted chain
	finalMainChain.insert(finalMainChain.begin(), newPendingChain.front()); 									// Insert the first element of the pending chain at the beginning of the main chain (as it is the smallest)
	std::vector<int> insertionIndices = generateInsertionIndices(newPendingChain.size()); 						// Generate the insertion indices based on Jacobsthal numbers for the remaining pending elements
	for(size_t i = 0; i < insertionIndices.size();i++) 															// Insert the remaining pending elements into the main chain at the correct positions determined by the insertion indices
	{
		int value = newPendingChain[insertionIndices[i]];
		std::vector<int>::iterator main_it = std::find(finalMainChain.begin(), finalMainChain.end(), newMainChain[insertionIndices[i]]); 	// Find the position of the current pending element in the new main chain
		std::vector<int>::iterator it = std::lower_bound(finalMainChain.begin(), main_it, value); 				// Find the correct position to insert the pending element in the main chain
		finalMainChain.insert(it, value); 																		// Insert the pending element into the main chain at the correct position
	}
	return (finalMainChain);
}


std::deque<int> PmergeMe::recDque(std::deque<int> dequee)
{
	int lastElement = 0;
	bool hasLastElement = false;
	if (dequee.size() <= 1)
		return dequee;
	if(dequee.size() % 2 != 0)
	{
		lastElement = dequee.back();
		dequee.pop_back();
		hasLastElement = true;
	}
	
	std::deque<int> mainChain;
	std::deque<int> pendingChain;

	for(size_t i = 0; i < dequee.size(); i += 2) 																// Process pairs of elements in the input vector
	{
		if(dequee[i] > dequee[i + 1]) 																			// store the larger element in the main chain and the smaller element in the pending chain
		{
			mainChain.push_back(dequee[i]);
			pendingChain.push_back(dequee[i + 1]);
		}
		else
		{
			mainChain.push_back(dequee[i + 1]);
			pendingChain.push_back(dequee[i]);
		}
	}
	std::deque<int> newMainChain = recDque(mainChain);
	std::deque<int> newPendingChain;
	for(size_t i = 0; i < newMainChain.size(); i++) 															// Reconstruct pending chain based on the order of the new main chain (to maintain the correct pairs)
	{
		size_t oldindex = std::find(mainChain.begin(), mainChain.end(), newMainChain[i]) - mainChain.begin();
		newPendingChain.push_back(pendingChain[oldindex]);
	}
	if (hasLastElement)
		newPendingChain.push_back(lastElement); 																// If there was an odd element, add it to the pending chain
	std::deque<int> finalMainChain = newMainChain; 																// Start with the new main chain as the base for the final sorted chain
	
	finalMainChain.insert(finalMainChain.begin(), newPendingChain.front());										// Insert the first element of the pending chain at the beginning of the main chain (as it is the smallest)
	std::vector<int> insertionIndices = generateInsertionIndices(newPendingChain.size()); 						// Generate the insertion indices based on Jacobsthal numbers for the remaining pending elements
	for(size_t i = 0; i < insertionIndices.size();i++) 															// Insert the remaining pending elements into the main chain at the correct positions determined by the insertion indices
	{
		int value = newPendingChain[insertionIndices[i]];
		std::deque<int>::iterator main_it = std::find(finalMainChain.begin(), finalMainChain.end(), newMainChain[insertionIndices[i]]); 	// Find the position of the current pending element in the new main chain
		std::deque<int>::iterator it = std::lower_bound(finalMainChain.begin(), main_it, value); 				// Find the correct position to insert the pending element in the main chain
		finalMainChain.insert(it, value); 																		// Insert the pending element into the main chain at the correct position
	}
	return (finalMainChain);
}

void PmergeMe::sortContainers()
{
	struct timeval vctrStart, vctrEnd, dqueStart, dqueEnd;
	gettimeofday(&vctrStart, NULL);
	this->vctr = recVctr(this->vctr);
	gettimeofday(&vctrEnd, NULL);
	gettimeofday(&dqueStart, NULL);
	this->dque = recDque(this->dque);
	gettimeofday(&dqueEnd, NULL);

		this->vctrTime = (vctrEnd.tv_sec - vctrStart.tv_sec) * 1000000L + (vctrEnd.tv_usec - vctrStart.tv_usec);
		this->dqueTime = (dqueEnd.tv_sec - dqueStart.tv_sec) * 1000000L + (dqueEnd.tv_usec - dqueStart.tv_usec);
}

// Check if a std::vector<int> is sorted in non-decreasing order
bool PmergeMe::vctr_is_sorted()
{
	for (size_t i = 1; i < vctr.size(); ++i)
	{
		if (vctr[i-1] > vctr[i])
			return false;
	}
	return true;
}

// Check if a std::deque<int> is sorted in non-decreasing order
bool PmergeMe::dque_is_sorted()
{
	for (size_t i = 1; i < dque.size(); ++i)
	{
		if (dque[i-1] > dque[i])
			return false;
	}
	return true;
}

