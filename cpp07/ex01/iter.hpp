/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:52:19 by mazaid            #+#    #+#             */
/*   Updated: 2026/01/07 16:31:51 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename Func>
void iter(T *array, size_t const length, Func f)
{
	for (size_t i = 0; i < length; i++)
	{
		f(array[i]);
	}
}
#endif