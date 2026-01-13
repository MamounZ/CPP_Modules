/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:42:26 by mazaid            #+#    #+#             */
/*   Updated: 2026/01/13 19:26:57 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>

class BitcoinExchange
{
	private:
	std::map<std::string, float> input;
	std::map<std::string, float> dataBase;
	BitcoinExchange();

	public:
	BitcoinExchange(std::string inputFile);
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	void parseDataBase();
	void parseInputFile(std::string inputFile);
	bool isValidDate(const std::string &date);

};

#endif
