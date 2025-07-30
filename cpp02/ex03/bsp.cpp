/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 20:33:05 by mazaid            #+#    #+#             */
/*   Updated: 2025/07/25 14:42:50 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

// int cross(Point const &a, Point const &b, Point const &p)
// {
// 	int cnt = 0;
// 	float py = p.getY().toFloat();
// 	float px = p.getX().toFloat();
// 	float ay = a.getY().toFloat();
// 	float ax = a.getX().toFloat();
// 	float by = b.getY().toFloat();
// 	float bx = b.getX().toFloat();

// 	if (((py < ay) != ((py < by)))
// 		&& (px < ax + ((py - ay) / (by - ay) * (bx - ax))))
// 			cnt++;
// 	return(cnt);
// }

// bool bsp(Point const a, Point const b, Point const c, Point const p)
// {
// 	int cp1 = cross(a, b, p);
// 	int cp2 = cross(b, c, p);
// 	int cp3 = cross(c, a, p);
// 	int total = cp1 + cp2 + cp3;
// 	return (total % 2 == 1);
// }

//////////////////////////////////////////////////////////////////////

Fixed cross(Point const &p1, Point const &p2, Point const &p0)
{
	Fixed p0y = p0.getY();
	Fixed p0x = p0.getX();
	Fixed p1y = p1.getY();
	Fixed p1x = p1.getX();
	Fixed p2y = p2.getY();
	Fixed p2x = p2.getX();

	return (p0x - p1x) * (p2y - p1y) - (p2x - p1x) * (p0y - p1y);
}

bool bsp(Point const a, Point const b, Point const c, Point const p)
{
	Fixed cp1 = cross(a, b, p);
	Fixed cp2 = cross(b, c, p);
	Fixed cp3 = cross(c, a, p);

	return (cp1 > 0 && cp2 > 0 && cp3 > 0) || (cp1 < 0 && cp2 < 0 && cp3 < 0);
}
