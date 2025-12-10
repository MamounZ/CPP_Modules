/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:33:20 by mazaid            #+#    #+#             */
/*   Updated: 2025/12/10 22:02:57 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <stdexcept>
#include <set>
#include <algorithm>

class Span
{
	private:
	std::set<int> s;
	unsigned int	max_size;


	public:
	Span();
	Span(unsigned int N);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();
	void addNumber(int n);
	unsigned int shortestSpan();
	unsigned int longestSpan();
	template <typename InputIterator>
	void addRange(InputIterator first, InputIterator last);
};

template <typename InputIterator>
void Span::addRange(InputIterator first, InputIterator last)
{
	while (first != last)
	{
		if (s.size() == max_size)
			throw std::runtime_error("Span is full");
		s.insert(*first);
		++first;
	}
}
#endif