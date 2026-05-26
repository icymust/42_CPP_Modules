/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martinmust <martinmust@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 12:32:06 by mmustone          #+#    #+#             */
/*   Updated: 2026/05/26 23:09:38 by martinmust       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name){
    name_ = name;
    weapon_ = NULL;
}

void HumanB::setWeapon(Weapon &weapon){
    weapon_ = &weapon;
}

void HumanB::attack()
{
    if (weapon_)
        std::cout << name_ << " attacks with their " << weapon_->getType() << std::endl;
}
