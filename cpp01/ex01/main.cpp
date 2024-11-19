/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:30:07 by pepi              #+#    #+#             */
/*   Updated: 2024/11/14 13:37:36 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    int N = 1;
    Zombie* horde = zombieHorde(N, "HordeZombie");

    if (horde) 
    {
        for (int i = 0; i < N; ++i) 
        {
               horde[i].announce();
        }
         delete horde;
    }
    return 0;
}