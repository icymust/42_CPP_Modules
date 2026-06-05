/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 12:25:11 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/05 12:25:15 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
{
    type_ = "";
    std::cout << "WrongAnimal created without type" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
    type_ = type;
    std::cout << "WrongAnimal created with type: " << type_ << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    type_ = other.type_; 
	std::cout << "WrongAnimal " << this->type_ << " created copy" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& other)
{
    if(this != &other)
    {
        type_ = other.type_;
    }
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    return(*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return(this->type_);
}