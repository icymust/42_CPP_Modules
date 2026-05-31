/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martinmust <martinmust@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 22:08:11 by martinmust        #+#    #+#             */
/*   Updated: 2026/05/31 22:33:57 by martinmust       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "\n--- Basic actions ---" << std::endl;
	ClapTrap martin("Martin");
	martin.attack("Bob");
	martin.takeDamage(5);
	martin.beRepaired(3);

	std::cout << "\n--- Fatal damage ---" << std::endl;
	ClapTrap bob("Bob");
	bob.takeDamage(20);
	bob.attack("Martin");
	bob.beRepaired(5);

	std::cout << "\n--- Energy test ---" << std::endl;
	ClapTrap alex("Alex");
	for (int i = 0; i < 11; i++)
		alex.attack("target");

	std::cout << "\n--- Copy test ---" << std::endl;
	ClapTrap original("Original");
	ClapTrap copy(original);
	copy.attack("someone");

	std::cout << "\n--- Assignment test ---" << std::endl;
	ClapTrap assigned("Assigned");
	assigned = original;
	assigned.attack("another target");

	return(0);
}
