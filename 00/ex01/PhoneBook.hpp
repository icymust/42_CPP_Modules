/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 17:43:00 by martinmust        #+#    #+#             */
/*   Updated: 2026/04/20 15:25:27 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <unistd.h>

class Contact
{
public:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string dark_secret;
};

class PhoneBook
{

private:
Contact contactsList[8];

public:
    int count;
    int flag;
    void add_contact();
    void search_contacts();
};

#endif