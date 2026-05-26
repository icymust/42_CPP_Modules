/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martinmust <martinmust@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 14:33:43 by mmustone          #+#    #+#             */
/*   Updated: 2026/05/26 23:54:54 by martinmust       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{
    name_ = "";
}

Zombie::~Zombie()
{
    std::cout << name_ << ": (died)" << std::endl;
}

void Zombie::announce()
{
    std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    name_ = name;
}