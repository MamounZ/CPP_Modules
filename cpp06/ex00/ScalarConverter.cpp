/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:46:02 by mazaid            #+#    #+#             */
/*   Updated: 2026/01/05 21:18:03 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

bool ScalarConverter::isChar(const std::string &str)
{
	return (str.length() == 3 && str[0] == '\'' && str[2] == '\'');
}

bool ScalarConverter::isInt(const std::string &str)
{
	if (str.empty())
		return (false);

	char *endptr;
	errno = 0;
	long value = std::strtol(str.c_str(), &endptr, 10);

	// Check: entire string consumed, no overflow, valid range
	return (*endptr == '\0' && endptr != str.c_str() && errno == 0 &&
	        value >= INT_MIN && value <= INT_MAX);
}

bool ScalarConverter::isFloat(const std::string &str)
{
	if (str.empty() || str[str.length() - 1] != 'f')
		return (false);

	char *endptr;
	std::strtof(str.c_str(), &endptr);

	// Check if 'f' is the last character and everything before was valid
	return (*endptr == 'f' && *(endptr + 1) == '\0' && endptr != str.c_str());
}

bool ScalarConverter::isDouble(const std::string &str)
{
	if (str.empty() || str[str.length() - 1] == 'f')
		return (false);

	char *endptr;
	std::strtod(str.c_str(), &endptr);

	// Check if entire string was consumed
	return (*endptr == '\0' && endptr != str.c_str());
}

bool ScalarConverter::isPseudoLiteral(const std::string &str)
{
	return (str == "nan" || str == "nanf" ||
	        str == "inf" || str == "inff" ||
	        str == "+inf" || str == "+inff" ||
	        str == "-inf" || str == "-inff");
}

void ScalarConverter::convertFromChar(const std::string &str)
{
	char c = str[1];

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1)
	          << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1)
	          << static_cast<double>(c) << std::endl;
}

void ScalarConverter::convertFromInt(const std::string &str)
{
	long long value = std::atoll(str.c_str());

	// Check for overflow
	if (value > INT_MAX || value < INT_MIN)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	int intValue = static_cast<int>(value);

	// Convert to char
	if (intValue < 0 || intValue > 127)
		std::cout << "char: impossible" << std::endl;
	else if (intValue < 32 || intValue > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(intValue) << "'" << std::endl;

	// Convert to int
	std::cout << "int: " << intValue << std::endl;

	// Convert to float
	std::cout << "float: " << std::fixed << std::setprecision(1)
	          << static_cast<float>(intValue) << "f" << std::endl;

	// Convert to double
	std::cout << "double: " << std::fixed << std::setprecision(1)
	          << static_cast<double>(intValue) << std::endl;
}

void ScalarConverter::convertFromFloat(const std::string &str)
{
	float floatValue = std::strtof(str.c_str(), NULL);

	// Convert to char
	if (std::isnan(floatValue) || std::isinf(floatValue) ||
	    floatValue < 0 || floatValue > 127)
		std::cout << "char: impossible" << std::endl;
	else if (floatValue < 32 || floatValue > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(floatValue) << "'" << std::endl;

	// Convert to int
	if (std::isnan(floatValue) || std::isinf(floatValue) ||
	    floatValue > 2147483647.0f || floatValue < -2147483648.0f)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(floatValue) << std::endl;

	// Convert to float
	std::cout << "float: " << std::fixed << std::setprecision(1)
	          << floatValue << "f" << std::endl;

	// Convert to double
	std::cout << "double: " << std::fixed << std::setprecision(1)
	          << static_cast<double>(floatValue) << std::endl;
}

void ScalarConverter::convertFromDouble(const std::string &str)
{
	double doubleValue = std::strtod(str.c_str(), NULL);

	// Convert to char
	if (std::isnan(doubleValue) || std::isinf(doubleValue) ||
	    doubleValue < 0 || doubleValue > 127)
		std::cout << "char: impossible" << std::endl;
	else if (doubleValue < 32 || doubleValue > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(doubleValue) << "'" << std::endl;

	// Convert to int
	if (std::isnan(doubleValue) || std::isinf(doubleValue) ||
	    doubleValue > INT_MAX || doubleValue < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(doubleValue) << std::endl;

	// Convert to float
	if (doubleValue > std::numeric_limits<float>::max() ||
	    doubleValue < -std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1)
		          << static_cast<float>(doubleValue) << "f" << std::endl;

	// Convert to double
	std::cout << "double: " << std::fixed << std::setprecision(1)
	          << doubleValue << std::endl;
}

void ScalarConverter::convertPseudoLiteral(const std::string &str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (str == "nan" || str == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str == "inf" || str == "inff" || str == "+inf" || str == "+inff")
	{
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
	}
	else if (str == "-inf" || str == "-inff")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void ScalarConverter::convert(const std::string &literal)
{
	if (isPseudoLiteral(literal))
		convertPseudoLiteral(literal);
	else if (isChar(literal))
		convertFromChar(literal);
	else if (isInt(literal))
		convertFromInt(literal);
	else if (isFloat(literal))
		convertFromFloat(literal);
	else if (isDouble(literal))
		convertFromDouble(literal);
	else
	{
		std::cout << "Error: Invalid input" << std::endl;
	}
}
