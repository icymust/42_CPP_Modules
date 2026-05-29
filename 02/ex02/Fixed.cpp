/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 15:56:53 by mmustone          #+#    #+#             */
/*   Updated: 2026/05/29 10:57:28 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
    raw_ = 0;
}

Fixed::Fixed(const int n)
{
    raw_ = n << fractionalBits_;
}

Fixed::Fixed(const float value)
{
    raw_ = roundf(value * (1 << fractionalBits_));
}

Fixed::Fixed(const Fixed &other)
{
    raw_ = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        raw_ = other.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
    return (raw_);
}

void Fixed::setRawBits(int const raw)
{
    raw_ = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)raw_ / (1 << fractionalBits_));
}

int Fixed::toInt(void) const
{
    return (raw_ >> fractionalBits_);
}

bool Fixed::operator>(const Fixed &other) const
{
    return (this->raw_ > other.raw_);
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (this->raw_ >= other.raw_);
}

bool Fixed::operator<(const Fixed &other) const
{
    return (this->raw_ < other.raw_);
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (this->raw_ <= other.raw_);
}

bool Fixed::operator==(const Fixed &other) const
{
    return (this->raw_ == other.raw_);
}

bool Fixed::operator!=(const Fixed &other) const
{
    return (this->raw_ != other.raw_);
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(this->raw_ + other.raw_);
    return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(this->raw_ - other.raw_);
    return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;
    result.setRawBits((this->raw_ * other.raw_) >> fractionalBits_);
    return (result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed result;
    result.setRawBits((this->raw_ << fractionalBits_) / other.raw_);
    return (result);
}

Fixed &Fixed::operator++()
{
    ++raw_;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    ++raw_;
    return (tmp);
}

Fixed &Fixed::operator--()
{
    --raw_;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    --raw_;
    return (tmp);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
    if (f1 < f2)
        return (f1);
    return (f2);
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
    if (f1 < f2)
        return (f1);
    return (f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
    if (f1 > f2)
        return (f1);
    return (f2);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
    if (f1 > f2)
        return (f1);
    return (f2);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}
