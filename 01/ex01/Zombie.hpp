/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martinmust <martinmust@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 14:07:57 by mmustone          #+#    #+#             */
/*   Updated: 2026/05/26 23:54:44 by martinmust       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP

#include <string>

class Zombie
{
private:
    std::string name_;

public:
    Zombie();
    ~Zombie();

    void setName(std::string);
    void announce();
};

Zombie* zombieHorde(int N, std::string name);

#endif