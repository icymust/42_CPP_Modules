/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 20:38:08 by mmustone          #+#    #+#             */
/*   Updated: 2026/05/22 13:24:54 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon):weapon_(weapon){
    name_ = name;
}

void HumanA::attack(){
    std::cout << name_ << " attacks with their " << weapon_.getType() << std::endl;
}