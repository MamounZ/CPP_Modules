/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <mazaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 22:12:18 by mazaid            #+#    #+#             */
/*   Updated: 2025/07/15 22:38:43 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact()
{
	FirstName = "";
	LastName = "";
	NickName = "";
	PhonrNumber = "";
	DarkestSecret = "";
}

void Contact::setFirstName(std::string firstName){FirstName = firstName;}
std::string Contact::getFirstName(void){return (FirstName);}
void Contact::setLastName(std::string lastName){LastName = lastName;}
std::string Contact::getLastName(void){	return (LastName);}
void Contact::setNickName(std::string nickName){NickName = nickName;}
std::string Contact::getNickName(void){return (NickName);}
void Contact::setPhonrNumber(std::string phonrNumber){PhonrNumber = phonrNumber;}
std::string Contact::getPhonrNumber(void){return (PhonrNumber);}
void Contact::setDarkestSecret(std::string darkestSecret){DarkestSecret = darkestSecret;}
std::string Contact::getDarkestSecret(void){return (DarkestSecret);}

void Contact::display()
{
	std::cout << "First Name: " << getFirstName() << "\n"
			  << "Last Name: " << getLastName() << "\n"
			  << "Nickname: " << getNickName() << "\n"
			  << "Phone Number: " << getPhonrNumber() << "\n"
			  << "Darkest Secret: " << getDarkestSecret() << "\n";
}
//////////////////////////////////////////////////////////
PhoneBook::PhoneBook()
{
	Count = 0;
	Count_clone = 0;
}
void PhoneBook::Add(Contact contact)
{
	Contacts[Count_clone % 8] = contact;
	Count_clone++;
	if (Count < 8)
		Count++;
}
std::string PhoneBook::truncateField(std::string str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}
void PhoneBook::DisplayAllContacts()
{
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	for (int i = 0; i < Count; i++)
	{
		std::cout << "|" << std::setw(10) << i;
		std::cout << "|" << std::setw(10) << truncateField(Contacts[i].getFirstName());
		std::cout << "|" << std::setw(10) << truncateField(Contacts[i].getLastName());
		std::cout << "|" << std::setw(10) << truncateField(Contacts[i].getNickName());
		std::cout << "|" << std::endl;
	}
	if (Count == 0)
	{
		std::cout << "No contacts to display.\n";
		return;
	}
	std::cout << "Enter the index of the contact you want to view: ";
	std::string input;
	std::getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cout << "Cancelled.\n";
		exit(0);
	}
	if (input.empty())
		return;
	if (input.length() != 1 || !isdigit(input[0]))
	{
		std::cout << "Invalid input: must be a digit between 0 and " << Count - 1 << ".\n";
		return;
	}
	int index = input[0] - '0';
	if (index < 0 || index >= Count)
	{
		std::cout << "Invalid index.\n";
		return;
	}
	Contacts[index].display();
}
