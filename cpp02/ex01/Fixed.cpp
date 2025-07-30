/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:19:44 by mazaid            #+#    #+#             */
/*   Updated: 2025/07/24 17:14:11 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	_fixedPointValue = 0;
}
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called\n";
	*this = other;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called\n";
	setRawBits(n << _fractionalBits);
}
Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called\n";
	setRawBits(roundf(n * (1 << _fractionalBits)));
}


Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
		_fixedPointValue = other._fixedPointValue;
	return (*this);
}


Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}
int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called\n";
	return(_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	_fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
	return (_fixedPointValue / (float)(1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
	return (_fixedPointValue >> _fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}