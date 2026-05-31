/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martinmust <martinmust@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 23:25:44 by martinmust        #+#    #+#             */
/*   Updated: 2026/06/01 00:44:58 by martinmust       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
	name_ = "";
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap created without name" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	name_ = name;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap created with name: " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	name_ = other.name_;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	std::cout << "ScavTrap " << this->name_ << " created copy" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		name_ = other.name_;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->name_ << " rip" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->energyPoints == 0)
	{
		std::cout << "ScavTrap Error Attack: Not enough energy" << std::endl;
		return;
	}

	if (this->hitPoints == 0)
	{
		std::cout << "ScavTrap Error Attack: No hit point" << std::endl;
		return;
	}

	this->energyPoints--;
	std::cout << "ScavTrap " << this->name_ << " attacks " << target
			  << ", causing " << this->attackDamage << " points of damage!"
			  << std::endl;
	return;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name_ << " is now in Gate keeper mode" << std::endl;
}
