/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 11:33:55 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/06 15:52:36 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Character.hpp"
#include <iostream>

Character::Character()
{
    name_ = "default";
    for (int i = 0; i < 4; i++)
        inventory_[i] = NULL;
}

Character::Character(std::string const &name)
{
    name_ = name;
    for (int i = 0; i < 4; i++)
        inventory_[i] = NULL;
}

Character::Character(const Character &other)
{
    name_ = other.name_;
    for (int i = 0; i < 4; i++)
    {
        if (other.inventory_[i])
            inventory_[i] = other.inventory_[i]->clone();
        else
            inventory_[i] = NULL;
    }
}

Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        name_ = other.name_;
        for (int i = 0; i < 4; i++)
        {
            delete inventory_[i];
            inventory_[i] = NULL;
            if (other.inventory_[i])
                inventory_[i] = other.inventory_[i]->clone();
        }
    }
    return (*this);
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
        delete inventory_[i];
}

std::string const &Character::getName() const
{
    return (this->name_);
}

void Character::equip(AMateria *m)
{
    if (m == NULL)
        return;

    for (int i = 0; i < 4; i++)
    {
        if (inventory_[i] == NULL)
        {
            inventory_[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3)
        return;

    inventory_[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx > 3)
        return;
    if (inventory_[idx] == NULL)
        return;
    inventory_[idx]->use(target);
}