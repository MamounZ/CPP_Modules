/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 21:30:07 by mazaid            #+#    #+#             */
/*   Updated: 2026/01/13 22:17:40 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cctype>

RPN::RPN(){}

RPN::RPN(std::string expression)
{
	operands = std::stack<double>();
	this->expression = expression;
}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		operands = other.operands;
		expression = other.expression;
	}
	return (*this);
}

RPN::~RPN() {}

void RPN::calculate()
{
	if (expression.empty()|| expression.find_first_not_of(' ') == std::string::npos)
	{
		throw std::runtime_error("Error: empty expression.");
	}
	for (size_t i = 0; i < expression.length(); i++)
	{
		char token = expression[i];
		if (std::isdigit(token))
		{
			operands.push(token - '0');
		}
		else if(token == '+' || token == '-' || token == '*' || token == '/')
		{
			if (operands.size() < 2)
			{
				throw std::runtime_error("Error: insufficient operands.");
			}
			double operand2 = operands.top();
			operands.pop();
			double operand1 = operands.top();
			operands.pop();
			double result;
			switch (token)
			{
				case '+':
					result = operand1 + operand2;
					break;
				case '-':
					result = operand1 - operand2;
					break;
				case '*':
					result = operand1 * operand2;
					break;
				case '/':
					if (operand2 == 0)
					{
						throw std::runtime_error("Error: division by zero.");
					}
					result = operand1 / operand2;
					break;
			}
			operands.push(result);
		}
		else if (token != ' ')
		{
			throw std::runtime_error("Error: invalid character.");
		}
	}
	if (operands.size() != 1)
	{
		throw std::runtime_error("Error: too many operands left in stack.");
	}
	std::cout << operands.top() << "\n";
}

