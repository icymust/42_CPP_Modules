/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 14:07:57 by mmustone          #+#    #+#             */
/*   Updated: 2026/05/15 16:21:37 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP

#include <iostream>
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