/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martinmust <martinmust@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 22:08:11 by martinmust        #+#    #+#             */
/*   Updated: 2026/06/01 02:04:36 by martinmust       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "\n--- FragTrap basic test ---" << std::endl;
	FragTrap frag("Fraggy");

	frag.attack("Robot");
	frag.takeDamage(40);
	frag.beRepaired(20);
	frag.highFivesGuys();

	std::cout << "\n--- Fatal damage test ---" << std::endl;
	FragTrap dead("DeadFrag");

	dead.takeDamage(200);
	dead.attack("Robot");
	dead.beRepaired(10);
	dead.highFivesGuys();

	std::cout << "\n--- Energy test ---" << std::endl;
	FragTrap tired("TiredFrag");

	for (int i = 0; i < 101; i++)
		tired.attack("target");

	std::cout << "\n--- Copy test ---" << std::endl;
	FragTrap original("OriginalFrag");
	FragTrap copy(original);

	copy.attack("CopyTarget");
	copy.highFivesGuys();

	std::cout << "\n--- Assignment test ---" << std::endl;
	FragTrap assigned("AssignedFrag");

	assigned = original;
	assigned.attack("AssignedTarget");
	assigned.highFivesGuys();

	return (0);
}
