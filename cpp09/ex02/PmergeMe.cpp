/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:55:18 by mazaid            #+#    #+#             */
/*   Updated: 2026/01/21 20:14:20 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void PmergeMe::parseInput(int argc, char **argv)
{
    for (int i = 1; i < argc; ++i)
    {
        std::string s(argv[i]);
        if (s.empty())
            throw std::runtime_error("invalid input: empty argument");
        for (size_t j = 0; j < s.length(); ++j)
        {
            if (!std::isdigit(static_cast<unsigned char>(s[j])))
                throw std::runtime_error("invalid input: non-digit character");
        }
        char *endptr;
        long numLong = std::strtol(s.c_str(), &endptr, 10);
        if (*endptr != '\0')
            throw std::runtime_error("invalid input: conversion error");
        if (numLong > 2147483647)
            throw std::runtime_error("invalid input: number too large");
        int num = static_cast<int>(numLong);
        if (num < 0)
            throw std::runtime_error("invalid input: negative number");
        vec.push_back(num);
        deq.push_back(num);
    }
}

void PmergeMe::sort()
{
    // Sort vector with timing
    std::vector<int> vecCopy = vec;
    clock_t start = clock();
    fordJohnsonVec(vecCopy);
    clock_t end = clock();
    vecTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
    vecSorted = vecCopy;

    // Sort deque with timing
    std::deque<int> deqCopy = deq;
    start = clock();
    fordJohnsonDeq(deqCopy);
    end = clock();
    deqTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
    deqSorted = deqCopy;
}

// Generate Jacobsthal-based insertion order for pend elements
std::vector<size_t> PmergeMe::generateJacobsthalOrder(size_t pendSize)
{
    std::vector<size_t> jacobsthal;
    std::vector<size_t> order;

    if (pendSize == 0)
        return order;

    // Generate Jacobsthal numbers: J(0)=0, J(1)=1, J(n)=J(n-1)+2*J(n-2)
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    while (jacobsthal.back() < pendSize)
    {
        size_t next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        jacobsthal.push_back(next);
    }

    // Build insertion order using Jacobsthal sequence
    // Start from index 1 (index 0 is always inserted first separately)
    std::vector<bool> used(pendSize, false);
    used[0] = true; // First element always inserted first

    for (size_t i = 2; i < jacobsthal.size(); ++i)
    {
        size_t jVal = jacobsthal[i];
        size_t prevJVal = jacobsthal[i - 1];

        // Insert from jVal down to prevJVal+1
        for (size_t k = std::min(jVal, pendSize); k > prevJVal; --k)
        {
            if (k - 1 < pendSize && !used[k - 1])
            {
                order.push_back(k - 1);
                used[k - 1] = true;
            }
        }
    }

    // Add any remaining elements not yet in order
    for (size_t i = 1; i < pendSize; ++i)
    {
        if (!used[i])
            order.push_back(i);
    }

    return order;
}

// Binary search for vector: find position to insert value in sorted arr[0..end)
size_t PmergeMe::binarySearchVec(const std::vector<int> &arr, int value, size_t end)
{
    size_t left = 0;
    size_t right = end;
    while (left < right)
    {
        size_t mid = left + (right - left) / 2;
        if (arr[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

// Binary search for deque: find position to insert value in sorted arr[0..end)
size_t PmergeMe::binarySearchDeq(const std::deque<int> &arr, int value, size_t end)
{
    size_t left = 0;
    size_t right = end;
    while (left < right)
    {
        size_t mid = left + (right - left) / 2;
        if (arr[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

// Ford-Johnson algorithm for vector
void PmergeMe::fordJohnsonVec(std::vector<int> &arr)
{
    if (arr.size() <= 1)
        return;

    // Step 1: Create pairs, ensure larger element is first (a > b)
    std::vector<std::pair<int, int> > pairs;
    int straggler = -1;
    bool hasStraggler = false;

    for (size_t i = 0; i + 1 < arr.size(); i += 2)
    {
        int a = arr[i];
        int b = arr[i + 1];
        if (a < b)
            std::swap(a, b);
        pairs.push_back(std::make_pair(a, b)); // a is larger, b is smaller
    }
    if (arr.size() % 2 == 1)
    {
        straggler = arr[arr.size() - 1];
        hasStraggler = true;
    }

    // Step 2: Extract main chain (larger elements) and recursively sort
    std::vector<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i)
        mainChain.push_back(pairs[i].first);

    fordJohnsonVec(mainChain);

    // Step 3: Rearrange pend to match the new order of mainChain
    // Build a map from mainChain values to their corresponding pend values
    std::vector<int> pend;
    for (size_t i = 0; i < mainChain.size(); ++i)
    {
        // Find which pair had this mainChain[i] as its larger element
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (pairs[j].first == mainChain[i])
            {
                pend.push_back(pairs[j].second);
                pairs[j].first = -1; // Mark as used to handle duplicates
                break;
            }
        }
    }
    if (hasStraggler)
        pend.push_back(straggler);

    // Step 4: Insert first pend element (it's smaller than first main element)
    if (!pend.empty())
    {
        mainChain.insert(mainChain.begin(), pend[0]);
    }

    // Step 5: Insert remaining pend elements using Jacobsthal order
    std::vector<size_t> insertOrder = generateJacobsthalOrder(pend.size());
    
    for (size_t i = 0; i < insertOrder.size(); ++i)
    {
        size_t pendIdx = insertOrder[i];
        if (pendIdx >= pend.size())
            continue;
        
        int value = pend[pendIdx];
        
        // Find the bound: position of the paired main element
        // The paired main element was at index pendIdx in original mainChain
        // After insertions, we need to find where it is now
        size_t bound = mainChain.size();
        
        // For regular pend elements (not straggler), search up to their paired element
        // For simplicity, search full range (a more optimized version would track positions)
        (void)pendIdx; // suppress unused warning in simplified version
        bound = mainChain.size();
        
        size_t pos = binarySearchVec(mainChain, value, bound);
        mainChain.insert(mainChain.begin() + pos, value);
    }

    arr = mainChain;
}

// Ford-Johnson algorithm for deque
void PmergeMe::fordJohnsonDeq(std::deque<int> &arr)
{
    if (arr.size() <= 1)
        return;

    // Step 1: Create pairs, ensure larger element is first (a > b)
    std::deque<std::pair<int, int> > pairs;
    int straggler = -1;
    bool hasStraggler = false;

    for (size_t i = 0; i + 1 < arr.size(); i += 2)
    {
        int a = arr[i];
        int b = arr[i + 1];
        if (a < b)
            std::swap(a, b);
        pairs.push_back(std::make_pair(a, b)); // a is larger, b is smaller
    }
    if (arr.size() % 2 == 1)
    {
        straggler = arr[arr.size() - 1];
        hasStraggler = true;
    }

    // Step 2: Extract main chain (larger elements) and recursively sort
    std::deque<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i)
        mainChain.push_back(pairs[i].first);

    fordJohnsonDeq(mainChain);

    // Step 3: Rearrange pend to match the new order of mainChain
    std::deque<int> pend;
    std::deque<std::pair<int, int> > pairsCopy = pairs;
    for (size_t i = 0; i < mainChain.size(); ++i)
    {
        for (size_t j = 0; j < pairsCopy.size(); ++j)
        {
            if (pairsCopy[j].first == mainChain[i])
            {
                pend.push_back(pairsCopy[j].second);
                pairsCopy[j].first = -1;
                break;
            }
        }
    }
    if (hasStraggler)
        pend.push_back(straggler);

    // Step 4: Insert first pend element
    if (!pend.empty())
    {
        mainChain.push_front(pend[0]);
    }

    // Step 5: Insert remaining pend elements using Jacobsthal order
    std::vector<size_t> insertOrder = generateJacobsthalOrder(pend.size());
    
    for (size_t i = 0; i < insertOrder.size(); ++i)
    {
        size_t pendIdx = insertOrder[i];
        if (pendIdx >= pend.size())
            continue;
        
        int value = pend[pendIdx];
        size_t bound = mainChain.size();
        
        size_t pos = binarySearchDeq(mainChain, value, bound);
        mainChain.insert(mainChain.begin() + pos, value);
    }

    arr = mainChain;
}

void PmergeMe::displayResults()
{
    // Display "Before:" with original unsorted sequence
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); i++) 
    {
        std::cout << vec[i];
        if (i + 1 < vec.size())
            std::cout << " ";
    }
    std::cout << std::endl;

    // Display "After:" with sorted sequence
    std::cout << "After:  ";
    for (size_t i = 0; i < vecSorted.size(); i++)
    {
        std::cout << vecSorted[i];
        if (i + 1 < vecSorted.size())
            std::cout << " ";
    }
    std::cout << std::endl;

    // Display timing for vector
    std::cout << "Time to process a range of " << vec.size() 
              << " elements with std::vector : " << vecTime << " us" << std::endl;

    // Display timing for deque
    std::cout << "Time to process a range of " << deq.size() 
              << " elements with std::deque  : " << deqTime << " us" << std::endl;
}

PmergeMe::PmergeMe() : vecTime(0), deqTime(0)
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    this->vec = other.vec;
    this->deq = other.deq;
    this->vecSorted = other.vecSorted;
    this->deqSorted = other.deqSorted;
    this->vecTime = other.vecTime;
    this->deqTime = other.deqTime;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        this->vec = other.vec;
        this->deq = other.deq;
        this->vecSorted = other.vecSorted;
        this->deqSorted = other.deqSorted;
        this->vecTime = other.vecTime;
        this->deqTime = other.deqTime;
    }
    return (*this);
}

PmergeMe::~PmergeMe(){}
    