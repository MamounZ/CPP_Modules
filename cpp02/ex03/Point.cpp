/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 20:11:27 by mazaid            #+#    #+#             */
/*   Updated: 2025/07/24 17:04:09 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0){}
Point::Point(const float num1, const float num2) : x(num1), y(num2){}
Point::Point(const Point &other) : x(other.getX()), y(other.getY()){}
Point &Point::operator=(const Point &other){(void)other; return (*this);}
Point::~Point() {}
Fixed Point::getX() const {return x;}
Fixed Point::getY() const {return y;}