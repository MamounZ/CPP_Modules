/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:19:44 by mazaid            #+#    #+#             */
/*   Updated: 2025/07/26 16:41:51 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	_fixedPointValue = 0;
}
Fixed::Fixed(const Fixed &other)
{
	*this = other;
}
Fixed::Fixed(const int n)
{
	setRawBits(n << _fractionalBits);
}
Fixed::Fixed(const float n)
{
	setRawBits(roundf(n * (1 << _fractionalBits)));
}
Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		_fixedPointValue = other._fixedPointValue;
	return (*this);
}

Fixed::~Fixed()
{

}
int Fixed::getRawBits() const
{
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

bool Fixed::operator>(const Fixed &other) const
{
	return (this->getRawBits() > other.getRawBits());
}
bool Fixed::operator<(const Fixed &other) const
{
	return (this->getRawBits() < other.getRawBits());
}
bool Fixed::operator>=(const Fixed &other) const
{
	return (this->getRawBits() >= other.getRawBits());
}
bool Fixed::operator<=(const Fixed &other) const
{
	return (this->getRawBits() <= other.getRawBits());
}
bool Fixed::operator==(const Fixed &other) const
{
	return (this->getRawBits() == other.getRawBits());
}
bool Fixed::operator!=(const Fixed &other) const
{
	return (this->getRawBits() != other.getRawBits());
}
Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() + other.getRawBits());
	return (result);
}
Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() - other.getRawBits());
	return (result);
}
Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	result.setRawBits((this->getRawBits() * other.getRawBits() >> _fractionalBits));
	return (result);
}
Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	if (other.getRawBits() == 0)
	{
		std::cout << "You are dividing by Zero!!\n";
		exit(0);
	}
	result.setRawBits((this->getRawBits() << _fractionalBits) / other.getRawBits());
	return (result);
}
Fixed &Fixed::operator++()
{
	this->_fixedPointValue++;
	return (*this);
}
Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_fixedPointValue++;
	return (tmp);
}
Fixed &Fixed::operator--()
{
	this->_fixedPointValue--;
	return (*this);
}
Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_fixedPointValue--;
	return (tmp);
}
Fixed &Fixed::min(Fixed &num1, Fixed &num2)
{
	if (num1 > num2)
		return (num2);
	else
		return (num1);
}
const Fixed &Fixed::min(Fixed const &num1, Fixed const &num2)
{
	if (num1 > num2)
		return (num2);
	else
		return (num1);
}
Fixed &Fixed::max(Fixed &num1, Fixed &num2)
{
	if (num1 > num2)
		return (num1);
	else
		return (num2);
}
const Fixed &Fixed::max(Fixed const &num1, Fixed const &num2)
{
	if (num1 > num2)
		return (num1);
	else
		return (num2);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}