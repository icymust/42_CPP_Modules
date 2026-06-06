/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 10:54:28 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/06 15:51:33 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/AMateria.hpp"
#include <iostream>

AMateria::AMateria()
{
    type_ = "default";
}

AMateria::AMateria(const AMateria &other)
{
    type_ = other.type_;
}

AMateria::AMateria(std::string const &type)
{
    type_ = type;
}

AMateria &AMateria::operator=(const AMateria &other)
{
    if (this != &other)
        type_ = other.type_;
    return (*this);
}

AMateria::~AMateria()
{
}

std::string const &AMateria::getType() const
{
    return (type_);
}

void AMateria::use(ICharacter &target)
{
    (void)target;
}