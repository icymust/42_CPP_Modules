/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:26:27 by mmustone          #+#    #+#             */
/*   Updated: 2026/05/28 14:00:27 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
Вызывается, когда ты создаёшь объект без параметров:
    Fixed a;
*/
Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    raw_ = 0;
}

/*
Вызывается, когда создаётся новый объект как копия другого:
    Fixed a;
    Fixed b(a);
        или
    Fixed b = a;
*/
Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    raw_ = other.getRawBits();
}

/*
Вызывается, когда объект уже существует, и ты присваиваешь ему другой объект:
Fixed a;
Fixed b;

b = a;
*/
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    // проверяет, что объект не присваивается сам себе
    if (this != &other)
        raw_ = other.getRawBits();
    // return (*this); нужен, чтобы работали цепочки: a = b = c;
    return (*this);
}

// Вызывается, когда объект уничтожается.
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return(raw_);
}

void Fixed::setRawBits(int const raw)
{
    raw_ = raw;
}
