/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scavtrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:13:54 by rpepi             #+#    #+#             */
/*   Updated: 2024/11/18 14:13:56 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    this->gateKeeperMode = false;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " destroyed" << std::endl;
}

void ScavTrap::guardGate()
{
	if (gateKeeperMode == false)
	{
		gateKeeperMode = true;
		std::cout << "ScavTrap " << name << " is now in Gate Keeper mode" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << name << " is already in Gate Keeper mode" << std::endl;
	}
}

void ScavTrap::attack(const std::string& target)
{
	if (hitPoints <= 0 || energyPoints <= 0)
	{
		std::cout << "ScavTrap " << name << " cannot attack because it has no hit points or energy points" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	energyPoints--;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (hitPoints <= 0)
	{
		std::cout << "ScavTrap " << name << " cannot take damage because it has no hit points" << std::endl;
		return;
	}
	hitPoints -= amount;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (hitPoints <= 0 || energyPoints <= 0)
	{
		std::cout << "ScavTrap " << name << " cannot be repaired because it has no hit points or energy points" << std::endl;
		return;
	}
	hitPoints += amount;
	energyPoints--;
}
