/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 09:58:09 by mazaid            #+#    #+#             */
/*   Updated: 2025/07/29 12:02:56 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = "";
	}
	std::cout << "Brain's default constructors\n";
}

Brain::Brain(const Brain &other)
{
	*this = other;
	std::cout << "Brain's copy constructors\n";
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
		{
			for (int i = 0; i < 100; i++)
			{
				this->ideas[i] = other.ideas[i];
			}
		}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain is out\n";
}

void Brain::setIdea(int index, const std::string &idea)
{
	if (index >= 0 && index < 100)
		ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return ideas[index];
	return "";
}