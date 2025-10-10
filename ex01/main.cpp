#include "PhoneBook.hpp"
#include <limits>

int main()
{
    std::string input;

    PhoneBook myPhoneBook;

    std::cout << "Hello, enter your command (ADD, SEARCH, EXIT): ";
    while (19)
    {
        std::cin >> input;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (std::cin.eof())
        {
            std::cout << std::endl;
            break;
        }
        if (input == "EXIT")
            return(0);
        else if (input == "ADD")
            myPhoneBook.add();
        else if (input == "SEARCH")
            myPhoneBook.search();
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
    }
}