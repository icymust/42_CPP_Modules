/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martinmust <martinmust@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 16:14:59 by martinmust        #+#    #+#             */
/*   Updated: 2026/04/21 00:21:33 by martinmust       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    std::string cmd;
    PhoneBook book;
    book.count = 0;
    book.flag = 0;
    std::cout << "\033[2J\033[H\n" << std::flush;
    do
    {
        std::cout << "Choose action for PhoneBook (ADD, SEARCH, EXIT)\n";
        std::cout << "Command: ";
        if (!std::getline(std::cin, cmd))
            break;
        std::cout << '\n';
        if (cmd == "ADD")
            book.add_contact();
        else if (cmd == "SEARCH")
            book.search_contacts();
    } while (cmd != "EXIT");
}
