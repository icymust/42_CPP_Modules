/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martinmust <martinmust@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 16:20:00 by martinmust        #+#    #+#             */
/*   Updated: 2026/05/02 18:04:39 by martinmust       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce(void){
    std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name){
    name_ = name;
}

Zombie::~Zombie(){
    std::cout << name_ << ": (died)" << std::endl;
}
