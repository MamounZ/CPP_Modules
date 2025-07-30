/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:47:25 by mazaid            #+#    #+#             */
/*   Updated: 2025/07/27 20:00:26 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>

int main(int argc , char **argv)
{
	std::string str;
	int	i = 1;
	size_t j = 0;

	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << "\n";
		return 0;
	}
	while (i < argc)
	{
		str = argv[i];
		j = 0;
		while (j < str.length())
		{
			if (str[j] >= 97 && str[j] <= 122)
				str[j] -= 32;
			j++;
		}
		i++;
		std::cout << str << "\n";
	}
	return 0;
}