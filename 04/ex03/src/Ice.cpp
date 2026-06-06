/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 13:53:30 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/06 16:04:50 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Ice.hpp"
#include "../lib/ICharacter.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(const Ice &other) : AMateria(other)
{
}

Ice &Ice::operator=(const Ice &other)
{
    if(this != &other)
        AMateria::operator=(other);
    return(*this);
}

Ice::~Ice()
{
}

AMateria *Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}