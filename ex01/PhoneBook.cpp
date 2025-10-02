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

	std::cout << "Add your contact to the phonebook :" << std::endl;
    clearInputBuffer();
	std::cout << "First name : ";
	std::getline(std::cin, firstName);
	std::cout << "Last name : ";
	std::getline(std::cin, lastName);
	std::cout << "Nickname : ";
	std::getline(std::cin, nickname);
	std::cout << "Phone number : ";
	std::getline(std::cin, phoneNumber);
	std::cout << "Your darkest secret : ";
	std::getline(std::cin, darkestSecret);
	this->contact[this->index].setFirstName(firstName);
	this->contact[this->index].setLastName(lastName);
	this->contact[this->index].setNickname(nickname);
	this->contact[this->index].setPhoneNumber(phoneNumber);
	this->contact[this->index].setDarkestSecret(darkestSecret);
	this->index = increaseIndex(this->index);
	this->numberOfContact = increaseNumberOfContact(this->numberOfContact);
    std::cout << "Contact added !" << std::endl;
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

    std::cout << "     index|first name| last name|  nickname" << std::endl;

    if (this->numberOfContact == 0)
    {
        std::cout << "Phonebook is empty! Add contacts first." << std::endl;
        return;
    }

    i = 0;
    while (i < this->numberOfContact)
    {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << truncatedText(this->contact[i].getFirstName()) << "|";
        std::cout << std::setw(10) << truncatedText(this->contact[i].getLastName()) << "|";
        std::cout << std::setw(10) << truncatedText(this->contact[i].getNickname()) << std::endl;
        i++;
    }
    indexToSearch = -1;
    choice = -1;
    
    while (indexToSearch < 0 || indexToSearch > 7 || indexToSearch >= this->numberOfContact)
    {
        std::cout << "Enter the contact index you want to see : ";
        std::cin >> indexToSearch;
        if (std::cin.fail()) {
            std::cin.clear();
            clearInputBuffer();
            indexToSearch = -1;
        }
        else
        {
            clearInputBuffer();
            if (indexToSearch >= 0 && indexToSearch < 7 && indexToSearch < this->numberOfContact)
                break;
        }
        while (choice != 1 && choice != 2)
        {
            std::cout << "\nWrong index -> \n1: try again \n2: go back to the menu\n Your choice : ";
            std::cin >> choice;
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

    std::cout << "First name: " << this->contact[indexToSearch].getFirstName() << std::endl;
    std::cout << "Last name: " << this->contact[indexToSearch].getLastName() << std::endl;
    std::cout << "Nickname: " << this->contact[indexToSearch].getNickname() << std::endl;
    std::cout << "Phone number: " << this->contact[indexToSearch].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << this->contact[indexToSearch].getDarkestSecret() << std::endl;
}