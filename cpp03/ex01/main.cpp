/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:18:03 by rpepi             #+#    #+#             */
/*   Updated: 2024/11/18 14:02:57 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap bb8("BB-8");
	ScavTrap atlas("Atlas");

	bb8.attack("Atlas");
	atlas.guardGate();
	atlas.attack("BB-8");
	bb8.takeDamage(20);
	bb8.beRepaired(10);
	atlas.takeDamage(30);
	atlas.beRepaired(10);
	atlas.guardGate();
	bb8.attack("Atlas");
	atlas.takeDamage(30);
	atlas.beRepaired(10);
	atlas.guardGate();
	return 0;
}
