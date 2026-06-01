/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martinmust <martinmust@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 02:26:59 by martinmust        #+#    #+#             */
/*   Updated: 2026/06/01 15:04:10 by martinmust       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap created without name" << std::endl;
	name_ = "";
	ClapTrap::name_ = "_clap_name";
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 30;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	DiamondTrap::name_ = name;
	ClapTrap::name_ = name + "_clap_name";
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	name_ = other.name_;
	ClapTrap::name_ = other.name_ + "_clap_name";
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	std::cout << "DiamondTrap " << this->name_ << " created copy" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		name_ = other.name_;
		ClapTrap::name_ = other.name_ + "_clap_name";
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->name_ << " rip" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap whoAmI name: " << name_ << ", ClapTrap name: " << ClapTrap::name_ << std::endl;
}
