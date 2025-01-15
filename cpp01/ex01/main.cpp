/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:30:07 by pepi              #+#    #+#             */
/*   Updated: 2025/01/15 12:09:12 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    int N = 5;
    Zombie* horde = zombieHorde(N, "HordeZombie");

    if (horde) 
    {
        for (int i = 0; i < N; ++i) 
        {
               horde[i].announce();
        }
        delete[] horde;

    }
    return 0;
}