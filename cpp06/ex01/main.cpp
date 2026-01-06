/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 18:45:14 by mazaid            #+#    #+#             */
/*   Updated: 2026/01/06 15:48:39 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data data;
	data.value = 42;

	Data* original = &data;
	uintptr_t raw = Serializer::serialize(original);
	Data* restored = Serializer::deserialize(raw);

	std::cout << "Original: " << original << std::endl;
	std::cout << "Restored: " << restored << std::endl;
	std::cout << "Equal: " << (original == restored ? "YES" : "NO") << std::endl;
	std::cout << "Value: " << restored->value << std::endl;
	return 0;
}
