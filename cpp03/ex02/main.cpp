/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:18:03 by rpepi             #+#    #+#             */
/*   Updated: 2024/11/18 14:03:03 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap robot("R2D2");
	ScavTrap gardien("Terminator");
	FragTrap guerrier("Optimus");

	guerrier.highFivesGuys();
	robot.attack("Optimus");
	guerrier.takeDamage(30);
	gardien.attack("Optimus");
	guerrier.takeDamage(20);
	guerrier.beRepaired(10);
	guerrier.highFivesGuys();
	return 0;

}
