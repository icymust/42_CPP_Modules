/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:26:27 by mmustone          #+#    #+#             */
/*   Updated: 2026/05/28 15:01:43 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    raw_ = 0;
}

Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called" << std::endl;
    raw_ = n << fractionalBits_;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    raw_ = roundf(value*(1 << fractionalBits_));
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        raw_ = other.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    return(raw_);
}

void Fixed::setRawBits(int const raw)
{
    raw_ = raw;
}

float Fixed::toFloat(void) const
{
    return (float)raw_ / (1<<fractionalBits_);
}

int Fixed::toInt(void) const
{
    return raw_ >> fractionalBits_;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return (out);
}
