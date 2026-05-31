/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martinmust <martinmust@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 01:22:10 by martinmust        #+#    #+#             */
/*   Updated: 2026/06/01 02:06:52 by martinmust       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap created without name" << std::endl;
	name_ = "";
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	name_ = name;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap created with name: " << this->name_ << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	name_ = other.name_;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	std::cout << "FragTrap " << this->name_ << " created copy" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		name_ = other.name_;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->name_ << " rip" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (this->energyPoints == 0)
	{
		std::cout << "FragTrap Error Attack: Not enough energy" << std::endl;
		return;
	}

	if (this->hitPoints == 0)
	{
		std::cout << "FragTrap Error Attack: No hit point" << std::endl;
		return;
	}

	this->energyPoints--;
	std::cout << "FragTrap " << this->name_ << " attacks " << target
			  << ", causing " << this->attackDamage << " points of damage!"
			  << std::endl;
	return;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name_ << " requests high-fives" << std::endl;
}
