/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 11:21:30 by mmustone          #+#    #+#             */
/*   Updated: 2026/05/29 11:57:06 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//(A.x - P.x) * (B.y - P.y) - (B.x - P.x) * (A.y - P.y)
static Fixed sign(Point const p1, Point const p2, Point const p3)
{
    Fixed result = (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
    return (result);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed d1, d2, d3;

    d1 = sign(a, b, point);
    d2 = sign(b, c, point);
    d3 = sign(c, a, point);
    if (d1 == 0 || d2 == 0 || d3 == 0)
        return (false);
    if ((d1 > 0 && d2 > 0 && d3 > 0) || (d1 < 0 && d2 < 0 && d3 < 0))
        return (true);
    return (false);
}