/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:28:30 by mcarton           #+#    #+#             */
/*   Updated: 2025/10/15 15:09:36 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    std::string input;

    PhoneBook myPhoneBook;

    std::cout << BOLD << CYAN << "\n╔════════════════════════════════════════╗\n"
              << "║     📞  WELCOME TO PHONEBOOK  📞       ║\n"
              << "╚════════════════════════════════════════╝" << RESET << "\n\n"
              << YELLOW << "Available commands: " << RESET
              << GREEN << "ADD" << RESET << " | " << BLUE << "SEARCH" << RESET << " | " << RED 
              << "EXIT" << RESET << "\n\n" << BOLD << "> " << RESET;
    while (19)
    {
        std::cin >> input;
        std::cin.ignore(LLONG_MAX, '\n');
        if (std::cin.eof())
        {
           std::cout << std::endl;
           std::cout << MAGENTA << "\n👋 Goodbye! See you soon!\n" << RESET;
            return(0);
        }
        if (input == "EXIT")
        {
            std::cout << MAGENTA << "\n👋 Goodbye! See you soon!\n" << RESET;
            return(0);
        }
        else if (input == "ADD")
            myPhoneBook.add();
        else if (input == "SEARCH")
            myPhoneBook.search();
        else
            std::cout << RED << "❌ Unknown command! " << RESET << "Try: ADD, SEARCH, or EXIT\n"
                      << BOLD << "\n> " << RESET;
    }
}