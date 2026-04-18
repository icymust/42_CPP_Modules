/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martinmust <martinmust@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 21:52:36 by martinmust        #+#    #+#             */
/*   Updated: 2026/04/18 23:01:39 by martinmust       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char correct_char(char c)
{
    if (c > 96 && c < 123)
        return (c - 32);
    return (c);
}

int main(int aс, char **av)
{
    int i = 0, j = 0;
    if (aс <= 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    while (av[++i])
    {
        j = 0;
        while (av[i][j])
            std::cout << correct_char(av[i][j++]);
    }
    std::cout << "\n";
    return (0);
}
