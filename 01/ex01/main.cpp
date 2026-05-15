/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 14:06:17 by mmustone          #+#    #+#             */
/*   Updated: 2026/05/15 15:34:58 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){
    Zombie *horde = zombieHorde(5, "Zak");

    for(int i=0; i < 5; i++)
        horde[i].announce();

    delete[] horde;
}