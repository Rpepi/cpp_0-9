/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:48:13 by rpepi             #+#    #+#             */
/*   Updated: 2024/11/18 13:53:25 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		~Animal();
		void makeSound() const;
};

#endif