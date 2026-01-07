/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:24:44 by mazaid            #+#    #+#             */
/*   Updated: 2026/01/07 17:26:36 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <stdexcept>
#include <cstdlib>

template <typename T>
class Array
{
	private:
	T* _array;
	unsigned int _size;

	public:
	Array()
	{
		_array = new T[0];
		_size = 0;
	}

	Array(unsigned int _size)
	{
		_array = new T[_size]();
		this->_size = _size;
	}

	Array(const Array &other)
	{
		_size = other._size;
		if (_size == 0)
			_array = new T[0];
		else
		{
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = other._array[i];
		}
	}

	Array &operator=(const Array &other)
	{
		if (this != &other)
		{
			delete[] _array;
			_size = other._size;
			if (_size == 0)
				_array = new T[0];
			else
			{
				_array = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					_array[i] = other._array[i];
			}
		}
		return (*this);
	}

	~Array()
	{
		delete[] _array;
	}

	T &operator[](unsigned int index)
	{
		if (index >= _size)
			throw std::out_of_range("Array index out of range");
		return _array[index];
	}

	T &operator[](unsigned int index) const
	{
		if (index >= _size)
			throw std::out_of_range("Array index out of range");
		return _array[index];
	}

	unsigned int size() const
	{
		return (_size);
	}
};

#endif