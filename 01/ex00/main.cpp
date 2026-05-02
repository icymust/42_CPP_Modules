/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martinmust <martinmust@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 16:34:27 by martinmust        #+#    #+#             */
/*   Updated: 2026/05/02 18:06:20 by martinmust       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void){
    randomChump("Zak");
    Zombie *z = newZombie("Zuuk");
    z->announce();
    delete z;
    return(0);
}
