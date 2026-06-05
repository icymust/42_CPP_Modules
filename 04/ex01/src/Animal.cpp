/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 14:58:22 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/04 18:59:15 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Animal.hpp"
#include <iostream>

Animal::Animal()
{
    type_ = "";
    std::cout << "Animal created without type" << std::endl;
}

Animal::Animal(std::string type)
{
    type_ = type;
    std::cout << "Animal created with type: " << type_ << std::endl;
}

Animal::Animal(const Animal& other)
{
    type_ = other.type_; 
	std::cout << "Animal " << this->type_ << " created copy" << std::endl;
}

Animal &Animal::operator=(const Animal& other)
{
    if(this != &other)
    {
        type_ = other.type_;
    }
    std::cout << "Animal copy assignment operator called" << std::endl;
    return(*this);
}

Animal::~Animal()
{
    std::cout << "Animal destructor" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const
{
    return(this->type_);
}