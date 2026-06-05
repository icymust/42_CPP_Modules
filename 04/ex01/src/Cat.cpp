/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 15:06:43 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/05 18:00:34 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat")
{
    brain_ = new Brain();
    std::cout << "Cat created with brain" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    brain_ = new Brain(*other.brain_);
	std::cout << "Cat " << this->type_ << " created copy" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    if(this != &other)
    {
        Animal::operator=(other);
        *brain_ = *other.brain_;
    }
    std::cout << "Cat copy assignment operator called" << std::endl;
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor" << std::endl;
    delete brain_;
}

void Cat::makeSound() const
{
    std::cout << "Cat: Meowing" << std::endl;
}

std::string Cat::getType() const
{
    return(type_);
}