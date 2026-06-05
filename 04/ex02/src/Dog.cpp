/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 15:25:53 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/05 17:49:28 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog")
{
    brain_ = new Brain();
    std::cout << "Dog created with brain" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    brain_ = new Brain(*other.brain_);
	std::cout << "Dog created copy with brain" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    if(this != &other){
        Animal::operator=(other);
        *brain_ = *other.brain_;
    }
    std::cout << "Dog copy assignment operator called" << std::endl;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor" << std::endl;
    delete brain_;
}

void Dog::makeSound() const
{
    std::cout << "Dog: Barking" << std::endl;
}

std::string Dog::getType() const
{
    return(this->type_);
}