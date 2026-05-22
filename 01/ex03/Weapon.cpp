/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 13:56:56 by mmustone          #+#    #+#             */
/*   Updated: 2026/05/22 14:25:17 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string name){
    type_ = name;
}

const std::string &Weapon::getType() const{
    return(type_);
}

void Weapon::setType(std::string newType){
    type_ = newType;
}