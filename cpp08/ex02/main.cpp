/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:00:34 by mazaid            #+#    #+#             */
/*   Updated: 2026/01/11 17:49:56 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <algorithm>

// int main()
// {
// 	MutantStack<int> mstack;
// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << mstack.top() << std::endl;
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	mstack.push(0);
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
	
// 	std::stack<int> s(mstack);
// 	unsigned long stack_size = s.size();
// 	for (unsigned long i = 0; i < stack_size; i++)
// 	{
// 		std::cout << s.top() << std::endl;
// 		s.pop();	
// 	}
// 	return 0;
// }

int main()
{
    MutantStack<int> ms;

    ms.push(10);
    ms.push(20);
    ms.push(30);

    std::cout << "Top: " << ms.top() << std::endl;
    ms.pop();
    std::cout << "After pop, top: " << ms.top() << std::endl;
    std::cout << "Size: " << ms.size() << std::endl;

    std::cout << "\nForward:\n";
    for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
        std::cout << *it << std::endl;

    std::cout << "\nReverse:\n";
    for (MutantStack<int>::reverse_iterator it = ms.rbegin(); it != ms.rend(); ++it)
        std::cout << *it << std::endl;

    MutantStack<int>::iterator found = std::find(ms.begin(), ms.end(), 20);
    if (found != ms.end())
        std::cout << "\nFound 20\n";
    else
        std::cout << "\n20 not found\n";

    return 0;
}