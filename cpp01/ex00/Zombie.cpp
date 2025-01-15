/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:51:27 by pepi              #+#    #+#             */
/*   Updated: 2025/01/15 11:46:00 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {
    std::cout << name << " is created" << std::endl;
}

Zombie::~Zombie(void) 
{
    std::cout << name << " is destroyed." << std::endl;
}

void Zombie::announce(void) const 
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
