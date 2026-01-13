/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 21:21:42 by mazaid            #+#    #+#             */
/*   Updated: 2026/01/13 22:03:33 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>

class RPN
{
	private:
	std::stack<double> operands;
	std::string expression;
	RPN();

	public:
	RPN(std::string expression);
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();
	void calculate();

};

#endif
