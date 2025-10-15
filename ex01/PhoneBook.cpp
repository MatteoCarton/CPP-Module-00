/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:28:45 by mcarton           #+#    #+#             */
/*   Updated: 2025/10/15 12:52:43 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
    this->index = 0;
    this->numberOfContact = 0;
}

static int	increaseIndex(int index)
{
	if (index + 1 >= 8)
		index = 0;
	else
		index++;
	return (index);
}

static int	increaseNumberOfContact(int number)
{
	if (number >= 8)
		return (number);
	number++;
	return (number);
}

static void clearInputBuffer(void)
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void PhoneBook::add(void)
{
	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

	std::cout << CYAN << "\n┌─────────────────────────────────┐\n";
	std::cout << "│     ➕  ADD NEW CONTACT  ➕     │\n";
	std::cout << "└─────────────────────────────────┘" << RESET << "\n\n";

	std::cout << YELLOW << "📝 First name: " << RESET;
	std::getline(std::cin, firstName);
	if (std::cin.eof())
	    return (void)(std::cout << std::endl);

	std::cout << YELLOW << "📝 Last name: " << RESET;
	std::getline(std::cin, lastName);
	if (std::cin.eof())
        return (void)(std::cout << std::endl);

	std::cout << YELLOW << "📝 Nickname: " << RESET;
	std::getline(std::cin, nickname);
	if (std::cin.eof())
        return (void)(std::cout << std::endl);

	std::cout << YELLOW << "📝 Phone number: " << RESET;
	std::getline(std::cin, phoneNumber);
	if (std::cin.eof())
        return (void)(std::cout << std::endl);

	std::cout << YELLOW << "📝 Darkest secret: " << RESET;
	std::getline(std::cin, darkestSecret);
	if (std::cin.eof())
        return (void)(std::cout << std::endl);

	if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty())
	{
		std::cout << RED << "\n❌ Error: All fields must be filled!\n" << RESET;
		return;
	}
	this->contact[this->index].setFirstName(firstName);
	this->contact[this->index].setLastName(lastName);
	this->contact[this->index].setNickname(nickname);
	this->contact[this->index].setPhoneNumber(phoneNumber);
	this->contact[this->index].setDarkestSecret(darkestSecret);
	this->index = increaseIndex(this->index);
	this->numberOfContact = increaseNumberOfContact(this->numberOfContact);
    std::cout << GREEN << "\n✅ Contact successfully added!\n" << RESET;
}

static std::string truncatedText(std::string text)
{
    if (text.length() > 10)
    {
        text = text.substr(0, 9);
        text += ".";
    }
    return (text);
}

void PhoneBook::search(void)
{
    int i;
    int indexToSearch;
    int choice;

    std::cout << BLUE << "\n┌──────────────────────────────────┐\n";
    std::cout << "│     🔍  SEARCH CONTACTS  🔍      │\n";
    std::cout << "└──────────────────────────────────┘" << RESET << "\n\n";

    if (this->numberOfContact == 0)
    {
        std::cout << YELLOW << "⚠️  Phonebook is empty! Add contacts first.\n" << RESET;
        return;
    }

    std::cout << BOLD << CYAN;
    std::cout << "┌──────────┬──────────┬──────────┬──────────┐\n";
    std::cout << "│" << std::setw(10) << "INDEX" << "│";
    std::cout << std::setw(10) << "FIRST NAME" << "│";
    std::cout << std::setw(10) << "LAST NAME" << "│";
    std::cout << std::setw(10) << "NICKNAME" << "│\n";
    std::cout << "├──────────┼──────────┼──────────┼──────────┤\n" << RESET;

    i = 0;
    while (i < this->numberOfContact)
    {
        std::cout << CYAN << "│" << RESET << std::setw(10) << i << CYAN << "│" << RESET;
        std::cout << std::setw(10) << truncatedText(this->contact[i].getFirstName()) << CYAN << "│" << RESET;
        std::cout << std::setw(10) << truncatedText(this->contact[i].getLastName()) << CYAN << "│" << RESET;
        std::cout << std::setw(10) << truncatedText(this->contact[i].getNickname()) << CYAN << "│" << RESET << std::endl;
        i++;
    }
    std::cout << CYAN << "└──────────┴──────────┴──────────┴──────────┘" << RESET << "\n\n";

    indexToSearch = -1;
    choice = -1;

    while (indexToSearch < 0 || indexToSearch > 7 || indexToSearch >= this->numberOfContact)
    {
        std::cout << MAGENTA << "👉 Enter contact index: " << RESET;
        std::cin >> indexToSearch;
        if (std::cin.eof())
            return (void)(std::cout << std::endl);
        if (std::cin.fail()) {
            std::cin.clear();
            clearInputBuffer();
            indexToSearch = -1;
        }
        else
        {
            clearInputBuffer();
            if (indexToSearch >= 0 && indexToSearch < 8 && indexToSearch < this->numberOfContact)
                break;
        }
        if (std::cin.eof())
            return (void)(std::cout << std::endl);
        while (choice != 1 && choice != 2)
        {
            std::cout << RED << "\n❌ Wrong index!\n" << RESET;
            std::cout << YELLOW << "1: " << RESET << "Try again\n";
            std::cout << YELLOW << "2: " << RESET << "Go back to menu\n";
            std::cout << MAGENTA << "Your choice: " << RESET;
            std::cin >> choice;
            if (std::cin.eof())
                return (void)(std::cout << std::endl);
            if (std::cin.fail()) {
                std::cin.clear();
                clearInputBuffer();
                choice = -1;
            }
        }
        clearInputBuffer();
        if (choice == 2)
            return ;
        choice = -1;
    }

    std::cout << GREEN << "\n╔════════════════════════════════════════╗\n";
    std::cout << "║        CONTACT DETAILS                 ║\n";
    std::cout << "╚════════════════════════════════════════╝" << RESET << "\n\n";
    std::cout << CYAN << "👤 First name:     " << RESET << this->contact[indexToSearch].getFirstName() << std::endl;
    std::cout << CYAN << "👤 Last name:      " << RESET << this->contact[indexToSearch].getLastName() << std::endl;
    std::cout << CYAN << "🏷️  Nickname:       " << RESET << this->contact[indexToSearch].getNickname() << std::endl;
    std::cout << CYAN << "📞 Phone number:   " << RESET << this->contact[indexToSearch].getPhoneNumber() << std::endl;
    std::cout << CYAN << "🤫 Darkest secret: " << RESET << this->contact[indexToSearch].getDarkestSecret() << std::endl;
}