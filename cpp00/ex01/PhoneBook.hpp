/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 22:21:18 by mazaid            #+#    #+#             */
/*   Updated: 2025/07/15 22:33:54 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

class Contact
{
private:
	std::string FirstName;
	std::string LastName;
	std::string NickName;
	std::string PhonrNumber;
	std::string DarkestSecret;

public:
	Contact();
	void setFirstName(std::string firstName);
	std::string getFirstName(void);
	void setLastName(std::string lastName);
	std::string getLastName(void);
	void setNickName(std::string nickName);
	std::string getNickName(void);
	void setPhonrNumber(std::string phonrNumber);
	std::string getPhonrNumber(void);
	void setDarkestSecret(std::string darkestSecret);
	std::string getDarkestSecret(void);
	void display();
};

class PhoneBook
{
private:
	Contact Contacts[8];
	int Count;
	int Count_clone;

public:
	PhoneBook();
	void Add(Contact contact);
	std::string truncateField(std::string str);
	void DisplayAllContacts();
};

#endif