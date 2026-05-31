/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martinmust <martinmust@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 22:08:11 by martinmust        #+#    #+#             */
/*   Updated: 2026/06/01 00:20:26 by martinmust       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "\n--- ScavTrap basic test ---" << std::endl;
	ScavTrap bob("Bob");

	bob.attack("Robot");
	bob.takeDamage(30);
	bob.beRepaired(10);
	bob.guardGate();

	std::cout << "\n--- Fatal damage test ---" << std::endl;
	ScavTrap dead("Dead");

	dead.takeDamage(200);
	dead.attack("Robot");
	dead.beRepaired(50);
	dead.guardGate();

	std::cout << "\n--- Energy test ---" << std::endl;
	ScavTrap alex("Alex");

	for (int i = 0; i < 51; i++)
		alex.attack("target");

	std::cout << "\n--- Copy test ---" << std::endl;
	ScavTrap original("Original");
	ScavTrap copy(original);

	copy.attack("someone");
	copy.guardGate();

	std::cout << "\n--- Assignment test ---" << std::endl;
	ScavTrap assigned("Assigned");

	assigned = original;
	assigned.attack("another target");
	assigned.guardGate();

	return (0);
}
