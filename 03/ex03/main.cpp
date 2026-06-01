/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martinmust <martinmust@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 22:08:11 by martinmust        #+#    #+#             */
/*   Updated: 2026/06/01 02:48:20 by martinmust       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "\n--- DiamondTrap basic test ---" << std::endl;
	DiamondTrap diamond("Diamond");

	diamond.attack("Robot");
	diamond.takeDamage(30);
	diamond.beRepaired(10);
	diamond.whoAmI();

	std::cout << "\n--- Copy test ---" << std::endl;
	DiamondTrap copy(diamond);

	copy.attack("CopyTarget");
	copy.whoAmI();

	std::cout << "\n--- Assignment test ---" << std::endl;
	DiamondTrap assigned("Assigned");

	assigned = diamond;
	assigned.attack("AssignedTarget");
	assigned.whoAmI();

	return (0);
}
