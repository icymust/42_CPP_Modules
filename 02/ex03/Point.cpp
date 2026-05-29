/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 10:54:51 by mmustone          #+#    #+#             */
/*   Updated: 2026/05/29 11:13:33 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(const float xValue, const float yValue) : x(xValue), y(yValue)
{
}

Point::Point(const Point &other) : x(other.x), y(other.y)
{
}

Point &Point::operator=(const Point &other)
{
    (void)other;
    return (*this);
}

Point::~Point()
{
}

Fixed Point::getX() const
{
    return (x);
}

Fixed Point::getY() const
{
    return (y);
}
