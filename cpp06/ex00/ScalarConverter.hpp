/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:15:16 by mazaid            #+#    #+#             */
/*   Updated: 2025/12/05 18:52:26 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <limits>
#include <climits>
#include <cerrno>

class ScalarConverter
{
	private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();

	static bool isChar(const std::string &str);
	static bool isInt(const std::string &str);
	static bool isFloat(const std::string &str);
	static bool isDouble(const std::string &str);
	static bool isPseudoLiteral(const std::string &str);

	static void convertFromChar(const std::string &str);
	static void convertFromInt(const std::string &str);
	static void convertFromFloat(const std::string &str);
	static void convertFromDouble(const std::string &str);
	static void convertPseudoLiteral(const std::string &str);

	public:
	static void convert(const std::string &literal);
};

#endif
