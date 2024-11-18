/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:18:03 by rpepi             #+#    #+#             */
/*   Updated: 2024/11/18 14:00:39 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap wall_e("Wall-E");
	wall_e.attack("Cockroach");
	wall_e.takeDamage(5);
	wall_e.beRepaired(3);
	wall_e.attack("Cockroach");
	wall_e.takeDamage(5);
	wall_e.beRepaired(3);
	return 0;
}
