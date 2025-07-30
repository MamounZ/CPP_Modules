/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 22:38:17 by mazaid            #+#    #+#             */
/*   Updated: 2025/07/15 22:38:46 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook phoneBook;
	std::string choice;
	do
	{
		std::cout << "PhoneBook Menu:\n"
				  << "1. ADD\n"
				  << "2. SEARCH\n"
				  << "3. EXIT\n";
		std::cout << "Enter your choice: ";
		std::getline(std::cin, choice);
		if (choice == "ADD")
		{
			Contact contact;
			std::string input;

			std::cout << "Enter First Name: ";
			std::getline(std::cin, input);
			if (std::cin.eof() || input.empty())
				exit(0);
			contact.setFirstName(input);

			std::cout << "Enter Last Name: ";
			std::getline(std::cin, input);
			if (std::cin.eof() || input.empty())
				exit(0);
			contact.setLastName(input);

			std::cout << "Enter Nickname: ";
			std::getline(std::cin, input);
			if (std::cin.eof() || input.empty())
				exit(0);
			contact.setNickName(input);

			std::cout << "Enter Phone Number: ";
			std::getline(std::cin, input);
			if (std::cin.eof() || input.empty() || !std::atoi(input.c_str()))
				exit(0);
			contact.setPhonrNumber(input);

			std::cout << "Enter Darkest Secret: ";
			std::getline(std::cin, input);
			if (std::cin.eof() || input.empty())
				exit(0);
			contact.setDarkestSecret(input);

			phoneBook.Add(contact);
		}
		else if (choice == "SEARCH")
			phoneBook.DisplayAllContacts();
		else if (choice == "EXIT")
		{
			std::cout << "Exiting PhoneBook.\n";
			return (0);
		}
		else if (std::cin.eof())
			exit(0);
		else
			std::cout << "Invalid choice. Please try again.\n";
	} while (choice != "4");
	return (0);
}
