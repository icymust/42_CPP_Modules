/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 12:32:06 by mmustone          #+#    #+#             */
/*   Updated: 2026/05/22 14:09:55 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name){
    name_ = name;
}

void HumanB::setWeapon(Weapon &weapon){
    weapon_ = &weapon;
}

void HumanB::attack()
{
    if (weapon_)
        std::cout << name_ << " attacks with their " << weapon_->getType() << std::endl;
}
