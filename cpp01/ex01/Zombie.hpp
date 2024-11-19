/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:55:50 by pepi              #+#    #+#             */
/*   Updated: 2024/11/14 13:33:49 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
	public:
		Zombie(); 
		Zombie(std::string name);
		~Zombie();
		void announce(void) const;
		void setName(std::string name);
	private:
		std::string name;
};


Zombie* zombieHorde(int N, std::string name);

#endif
