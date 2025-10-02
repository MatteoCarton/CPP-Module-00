#include "PhoneBook.hpp"

int main()
{
    std::string input;

    PhoneBook myPhoneBook;

    std::cout << "Hello, enter your command (ADD, SEARCH, EXIT): ";
    while (19)
    {
        std::cin >> input;
        if (input == "EXIT")
            return(0);
        else if (input == "ADD")
            myPhoneBook.add();
        else if (input == "SEARCH")
            myPhoneBook.search();
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
    }
}