/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 19:49:31 by martinmust        #+#    #+#             */
/*   Updated: 2026/04/21 11:15:39 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static bool is_empty(std::string str)
{
    int i = 0;

    while(str[i])
    {
        if(str[i] != ' ' && str[i] != '\t')
            return(false);
        i++;
    }
    return(true);
}

void PhoneBook::add_contact()
{
    if (count == 8)
    {
        count = 0;
        flag = 1;
    }

    std::cout << "\033[2J\033[H\n" << std::flush;
    std::cout << "\tADD New Contact" << '\n';
    
    do
    {
        std::cout << "Enter first name: ";
        if (!std::getline(std::cin, contactsList[count].first_name))
            break;

    } while (is_empty(contactsList[count].first_name));

    do
    {
        std::cout << "Enter last name: ";
        if (!std::getline(std::cin, contactsList[count].last_name))
            break;

    } while (is_empty(contactsList[count].last_name));

    do
    {
        std::cout << "Enter nickname: ";
        if (!std::getline(std::cin, contactsList[count].nickname))
            break;

    } while (is_empty(contactsList[count].nickname));

    do
    {
        std::cout << "Enter phone number: ";
        if (!std::getline(std::cin, contactsList[count].phone_number))
            break;

    } while (is_empty(contactsList[count].phone_number));

    do
    {
        std::cout << "Enter dark secret: ";
        if (!std::getline(std::cin, contactsList[count].dark_secret))
            break;

    } while (is_empty(contactsList[count].dark_secret));

    count++;
    std::cout << "\033[2J\033[H\n" << std::flush;
}

static std::string check_string(std::string str)
{
    std::string new_str;

    if (str.length() > 10)
    {
        new_str = str.substr(0, 9);
        new_str += '.';
        return (new_str);
    }
    return (str);
}

static void print_short_contact(int count, int flag, Contact list[8])
{
    int i = 0, j = 0;
    if (flag == 1)
        i = 8;
    else
        i = count;

    for (; j < i; j++)
    {
        std::cout << std::setw(10) << j;
        std::cout << '|' << std::setw(10) << std::right << check_string(list[j].first_name);
        std::cout << '|' << std::setw(10) << std::right << check_string(list[j].last_name);
        std::cout << '|' << std::setw(10) << std::right << check_string(list[j].nickname);
        std::cout << '\n';
    }
}

static void print_short_header()
{
    std::cout << "\033[2J\033[H\n" << std::flush;
    std::cout << std::setw(10) << "index";
    std::cout << '|' << std::setw(10) << std::right << "first name";
    std::cout << '|' << std::setw(10) << std::right << "last name";
    std::cout << '|' << std::setw(10) << std::right << "nickname";
    std::cout << '\n';
}

static void print_full_contact(std::string index, Contact list[8])
{
    int num = 0;
    if(index[0])
        num = index[0] - '0';

    if (index[1] || (num > 7))
    {
        std::cout << "WRONG INPUT !\n";
        return;
    }

    std::cout << "\033[2J\033[H\n" << std::flush;
    std::cout << "\tContact info: " << num << '\n';
    std::cout << "First name: " << list[num].first_name << '\n';
    std::cout << "Last name: " << list[num].last_name << '\n';
    std::cout << "Nickname: " << list[num].nickname << '\n';
    std::cout << "Phone number: " << list[num].phone_number << '\n';
    std::cout << "Dark secret: " << list[num].dark_secret << '\n';
}

void PhoneBook::search_contacts()
{
    std::string index;

    print_short_header();
    print_short_contact(count, flag, contactsList);

    do
    {
        std::cout << "Enter index (0-7) or exit: ";
        if (!std::getline(std::cin, index))
            break;
        print_full_contact(index, contactsList);
        std::cout << '\n';
    } while (index != "exit");

    std::cout << "\033[2J\033[H\n" << std::flush;
}
