/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:04:25 by mazaid            #+#    #+#             */
/*   Updated: 2026/01/13 19:26:52 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(std::string inputFile)
{
	parseDataBase();
	parseInputFile(inputFile);
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		dataBase = other.dataBase;
		input = other.input;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::parseDataBase()
{
	std::ifstream dBFile("data.csv");
	if (!dBFile.is_open())
	{
		throw std::runtime_error("Error: could not open data.csv file.");
	}
	std::string line;
	std::string key;
	float value;
	unsigned long sep;

	std::getline(dBFile,line);
	while(std::getline(dBFile,line))
	{
		sep = line.find(',');
		key = line.substr(0, sep);
		value = std::atof(line.substr(sep + 1).c_str());
		dataBase[key] = value;
	}
	dBFile.close();
}
bool BitcoinExchange::isValidDate(const std::string &date)
{
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    return true;
}
void BitcoinExchange::parseInputFile(std::string inputFile)
{
	std::ifstream InputStream(inputFile.c_str());
	if (!InputStream.is_open())
	{
		throw std::runtime_error("Error: could not open input file.");
	}
	std::string line;
	std::string key;
	float value;
	unsigned long sep;

	std::getline(InputStream,line);
	while(std::getline(InputStream,line))
	{
		sep = line.find(" | ");
		if (sep == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}
		key = line.substr(0, sep);
		if (!isValidDate(key))
		{
			std::cerr << "Error: invalid date format => " << key << std::endl;
			continue;
		}

		std::string valueStr = line.substr(sep + 3);
		char *endPtr;
		value = std::strtof(valueStr.c_str(), &endPtr);
		if (*endPtr != '\0' && *endPtr != '\n')
		{
			std::cerr << "Error: invalid value => " << valueStr << std::endl;
			continue;
		}

		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue ;
		}
		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue ;
		}
		input[key] = value;
		std::map<std::string, float>::iterator it = dataBase.upper_bound(key);
		if (it == dataBase.begin())
		{
    		std::cerr << "Error: date too early" << std::endl;
			continue;
		}
		--it;

		std::cout << key << " => " << value << " = " << value * dataBase[it->first] << std::endl;
	}
	InputStream.close();
}
