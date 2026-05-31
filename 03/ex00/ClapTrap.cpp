/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martinmust <martinmust@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 19:06:07 by martinmust        #+#    #+#             */
/*   Updated: 2026/06/01 00:14:15 by martinmust       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap created without name" << std::endl;
	name_ = "";
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	name_ = name;
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
	std::cout << "ClapTrap created with name: " << this->name_ << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	name_ = other.name_;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	std::cout << "ClapTrap " << this->name_ << " created copy" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		name_ = other.name_;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return (*this);
}

void ClapTrap::attack(const std::string &target)
{
	if (this->energyPoints == 0)
	{
		std::cout << "ClapTrap Error Attack: Not enough energy" << std::endl;
		return;
	}

	if (this->hitPoints == 0)
	{
		std::cout << "ClapTrap Error Attack: No hit point" << std::endl;
		return;
	}

	this->energyPoints--;
	std::cout << "ClapTrap " << this->name_ << " attacks " << target
			  << ", causing " << this->attackDamage << " points of damage!"
			  << std::endl;
	return;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= this->hitPoints)
		this->hitPoints = 0;
	else
		this->hitPoints -= amount;
	std::cout << "ClapTrap " << this->name_ << " damaged: " << amount
			  << ", current HP: " << this->hitPoints
			  << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints == 0)
	{
		std::cout << "ClapTrap Error beRepaired: Not enough energy" << std::endl;
		return;
	}
	if (this->hitPoints == 0)
	{
		std::cout << "ClapTrap Error beRepaired: No hit points" << std::endl;
		return;
	}

	this->energyPoints--;
	this->hitPoints += amount;

	std::cout << "ClapTrap " << this->name_ << " repaired HP: " << amount
			  << ", current HP: " << this->hitPoints
			  << std::endl;
	return;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->name_ << " rip" << std::endl;
}
