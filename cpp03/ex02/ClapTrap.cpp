/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:14:24 by rpepi             #+#    #+#             */
/*   Updated: 2024/11/18 14:12:10 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << name << " created" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " destroyed" << std::endl;
}



void ClapTrap::attack(const std::string& target)
{
	if (hitPoints <= 0 || energyPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " cannot attack because it has no hit points or energy points" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " cannot take damage because it has no hit points" << std::endl;
		return;
	}
	hitPoints -= amount;
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints <= 0 || energyPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " cannot be repaired because it has no hit points or energy points" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << name << " is repaired for " << amount << " hit points" << std::endl;
	hitPoints += amount;
	energyPoints--;
}
