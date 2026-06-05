/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 15:06:43 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/04 19:06:10 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat created with type: " << type_ << std::endl;
}

Cat::Cat(const Cat &other)
{
    type_ = other.type_;
	std::cout << "Cat " << this->type_ << " created copy" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    if(this != &other)
    {
        type_ = other.type_;
    }
    std::cout << "Cat copy assignment operator called" << std::endl;
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Cat: Meowing" << std::endl;
}

std::string Cat::getType() const
{
    return(type_);
}