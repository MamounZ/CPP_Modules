/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:50:24 by mazaid            #+#    #+#             */
/*   Updated: 2025/12/10 22:03:03 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
	max_size = 0;
}
Span::Span(unsigned int N)
{
	max_size = N;
}

Span::Span(const Span &other)
{
	*this = other;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		s = other.s;
		max_size = other.max_size;
	}
	return (*this);
}

Span::~Span()
{

}

void Span::addNumber(int n)
{
	if (s.size() == max_size)
		throw std::runtime_error("Span is full");
	s.insert(n);
}

unsigned int Span::shortestSpan()
{
	if (s.size() < 2)
		throw std::runtime_error("not enough numbers");

	std::set<int>::iterator it = s.begin();
	int prev = *(it++);
	unsigned int min_span = *it - prev;
	for (; it != s.end(); it++)
	{
		min_span = std::min(min_span, static_cast<unsigned int>(*it - prev));
		prev = *it;
	}
	return (min_span);
}

unsigned int Span::longestSpan()
{
	if (s.size() < 2)
		throw std::runtime_error("Not enough numbers");
	return *(s.rbegin()) - *(s.begin());
}

