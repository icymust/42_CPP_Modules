/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 11:53:22 by mmustone          #+#    #+#             */
/*   Updated: 2026/05/29 12:09:52 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
    Point a(1, 1);
    Point b(2, 6);
    Point c(5, 4);
    Point point(-2, -4);

    bool result = bsp(a, b, c, point);
    std::cout << "Result: " << (result ? "true" : "false") << std::endl;
    return (0);
}