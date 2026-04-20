/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 19:49:31 by martinmust        #+#    #+#             */
/*   Updated: 2026/04/20 15:48:49 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::add_contact()
{
    if(count == 8){
        count = 0;
        flag = 1;
    }
        
    std::cout << "\033[2J\033[H\n" << std::flush;
    std::cout << "\tADD New Contact" << '\n';
    do {
        std::cout << "Enter first name: ";
        std::getline(std::cin, contactsList[count].first_name);

    } while(contactsList[count].first_name == "");

    do {
        std::cout << "Enter last name: ";
        std::getline(std::cin, contactsList[count].last_name);

    } while(contactsList[count].last_name == "");

    do {
        std::cout << "Enter nickname: ";
        std::getline(std::cin, contactsList[count].nickname);

    } while(contactsList[count].nickname == "");

    do {
        std::cout << "Enter phone number: ";
        std::getline(std::cin, contactsList[count].phone_number);

    } while(contactsList[count].phone_number == "");

    do {
        std::cout << "Enter dark secret: ";
        std::getline(std::cin, contactsList[count].dark_secret);

    } while(contactsList[count].dark_secret == "");

    count++;
    std::cout << "Contact saved !" << std::endl;
    usleep(2000000);
    std::cout << "\033[2J\033[H\n" << std::flush;
}

static void print_short_contact(int count, int flag, Contact list[8])
{
    int i = 0, j = 0;
    // std::string newStr;
    if (flag == 1)
        i = 8;
    else
        i = count;
    
    for(; j<i; j++)
    {

        std::cout << std::setw(10) << j;
        std::cout << '|' << std::setw(10) << list[j].first_name;
        std::cout << '|' << std::setw(10) << list[j].last_name;
        std::cout << '|' << std::setw(10) << list[j].nickname;
        std::cout << '\n';
    }
}

static void print_short_header()
{
    std::cout << "\033[2J\033[H\n" << std::flush;
    std::cout << std::setw(10) << "index";
    std::cout << '|' << std::setw(10) << "first name";
    std::cout << '|' << std::setw(10) << "last name";
    std::cout << '|' << std::setw(10) << "nickname";
    std::cout << '\n';
}

static void print_full_contact(std::string index, Contact list[8]){
    int num = 0;
    num = index[0] - '0';

    if (index[1] || (num > 7)){
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
    
    do {
        std::cout << "Enter index (0-7) or exit: ";
        std::getline(std::cin, index);
        print_full_contact(index, contactsList);
        std::cout << '\n';
    } while(index != "exit");

    std::cout << "\033[2J\033[H\n" << std::flush;
}
