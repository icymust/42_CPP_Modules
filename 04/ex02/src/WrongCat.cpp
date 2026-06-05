/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 12:23:22 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/05 12:26:22 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat created with type: " << type_ << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
{
    type_ = other.type_;
	std::cout << "WrongCat " << this->type_ << " created copy" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    if(this != &other)
    {
        type_ = other.type_;
    }
    std::cout << "Cat copy assignment operator called" << std::endl;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat: Meowing" << std::endl;
}

std::string WrongCat::getType() const
{
    return(type_);
}