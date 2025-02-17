/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:37:17 by pepi              #+#    #+#             */
/*   Updated: 2024/11/19 11:50:46 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("")
{
	std::cout << "Un Animal est venu au monde" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Un Animal est mort" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "* Son d'animal indéfini *" << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}

