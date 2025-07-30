/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:51:16 by mazaid            #+#    #+#             */
/*   Updated: 2025/07/20 18:28:00 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv)
{
	std::string str1;
	std::string str2;
	std::string file;
	std::string file2;
	std::string line;
	std::string line2;
	size_t pos;
	size_t found;

	if(argc != 4)
	{
		std::cout << "input Error\n";
		return (1);
	}
	file = argv[1];
	str1 = argv[2];
	str2 = argv[3];
	file2 = file + ".replace";
	if (str1.empty())
	{
		std::cerr << "Error: str1 cannot be empty.\n";
		return 1;
	}
	std::ifstream inputFile(file.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "Failed to open file\n";
		return 1;
	}
	std::ofstream outputFile(file2.c_str());
	if (!outputFile.is_open())
	{
		std::cerr << "Failed to create output file\n";
		return 1;
	}
	while (std::getline(inputFile, line))
	{
		found = 0;
		pos = 0;
		line2 = "";
		while ((found = line.find(str1, pos)) != std::string::npos)
		{
			line2 += line.substr(pos, found - pos);
			line2 += str2;
			pos = found + str1.length();
		}
		line2 += line.substr(pos);
		outputFile << line2;
		if (!inputFile.eof())
			outputFile << "\n";
	}
	inputFile.close();
	outputFile.close();
	return (0);
}