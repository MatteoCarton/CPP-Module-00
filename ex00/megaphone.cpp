/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:28:51 by mcarton           #+#    #+#             */
/*   Updated: 2025/10/15 12:28:52 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    int i = 1;
    int j;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return (0);
    }
    while (i < argc)
    {
        j = 0;
        while (argv[i][j])
        {
            std::cout << (char)std::toupper(argv[i][j]);
            j++;
        }
        i++;
    }
    std::cout << '\n';
    return 0;
}