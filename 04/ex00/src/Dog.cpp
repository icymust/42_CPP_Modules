/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 15:25:53 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/04 19:06:27 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog created with type: " << type_ << std::endl;
}

Dog::Dog(const Dog &other)
{
    type_ = other.type_;
	std::cout << "Dog " << this->type_ << " created copy" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    if(this != &other){
        type_ = other.type_;
    }
    std::cout << "Dog copy assignment operator called" << std::endl;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Dog: Barking" << std::endl;
}

std::string Dog::getType() const
{
    return(this->type_);
}