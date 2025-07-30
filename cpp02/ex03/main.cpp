/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:13:57 by mazaid            #+#    #+#             */
/*   Updated: 2025/07/24 21:08:50 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

void test(const Point &a, const Point &b, const Point &c, const Point &p, const std::string &label)
{
	std::cout << label << ": ";
	if (bsp(a, b, c, p))
		std::cout << "Inside\n";
	else
		std::cout << "Outside\n";
}
int main()
{
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(5.0f, 5.0f);
	// // Inside the triangle
	test(a, b, c, Point(5.0f, 2.0f), "Inside 1");
	test(a, b, c, Point(3.0f, 1.0f), "Inside 2");
	test(a, b, c, Point(7.0f, 1.0f), "Inside 3");
	// // // On the edge (should return false)
	test(a, b, c, Point(0.0f, 0.0f), "Vertex A");
	test(a, b, c, Point(10.0f, 0.0f), "Vertex B");
	test(a, b, c, Point(5.0f, 5.0f), "Vertex C");
	test(a, b, c, Point(5.0f, 0.0f), "Edge AB midpoint");
	test(a, b, c, Point(7.5f, 2.5f), "Edge BC midpoint");
	test(a, b, c, Point(2.5f, 2.5f), "Edge CA midpoint");
	// // // Outside the triangle
	test(a, b, c, Point(-13.0f, 1.0f), "Outside right");
	test(a, b, c, Point(-1.0f, -1.0f), "Outside bottom left");
	test(a, b, c, Point(5.0f, 6.0f), "Above vertex C");
	test(a, b, c, Point(10.1f, 0.1f), "Slightly outside B");
	// Near edges (floating-point precision)
	test(a, b, c, Point(5.0f, 0.0019545f), "Just above base");
	test(a, b, c, Point(10.00001f, 0.00001f), "Tiny bit outside");
	return 0;
}

// #include <iostream>
// #include "Point.hpp"

// int main()
// {
// 	// Triangle vertices
// 	Point a(0.0f, 0.0f);
// 	Point b(4.0f, 0.0f);
// 	Point c(2.0f, 3.0f);

// 	// Test points
// 	Point p1(1.0f, 1.0f);
// 	Point p2(5.0f, 2.0f);
// 	Point p3(2.0f, 0.0f);
// 	Point p4(2.0f, 2.f);

// 	std::cout << bsp(a, b, c, p1) << "\n";
// 	std::cout << bsp(a, b, c, p2) << "\n";
// 	std::cout << bsp(a, b, c, p3) << "\n";
// 	std::cout << bsp(a, b, c, p4) << "\n";

// 	return 0;
// }
