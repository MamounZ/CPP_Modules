/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:52:05 by mazaid            #+#    #+#             */
/*   Updated: 2025/12/09 16:39:29 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void print(T const &x) { std::cout << x << " "; }

int main()
{
	int arr1[] = {1, 2, 3};
	iter(arr1, 3, print<int>);

	std::cout << "\n\n";

	const int arr2[] = {10, 20, 30};
	iter(arr2, 3, print<int>);

	std::cout << "\n\n";

	float arr3[] = {1.5, 2.5, 3.5};
	iter(arr3, 3, print<float>);

	std::cout << "\n\n";

	const float arr4[] = {1.5, 2.5, 3.5};
	iter(arr4, 3, print<float>);

	return 0;
}