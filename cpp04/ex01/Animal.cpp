/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:37:17 by pepi              #+#    #+#             */
/*   Updated: 2024/11/19 12:15:14 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("")
{
	std::cout << "Un Animal est né" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Un Animal nous a quittés" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "* Son d'animal indéfini *" << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}

Animal::Animal(const Animal& other) {
    this->type = other.type;
    std::cout << "Un Animal a été cloné" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

