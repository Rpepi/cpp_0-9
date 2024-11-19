/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aanimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:37:17 by pepi              #+#    #+#             */
/*   Updated: 2024/11/19 12:27:25 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("")
{
	std::cout << "Un Animal est né" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "Un Animal nous a quittés" << std::endl;
}

void AAnimal::makeSound() const
{
	std::cout << "* Son d'animal indéfini *" << std::endl;
}

std::string AAnimal::getType() const
{
	return this->type;
}

AAnimal::AAnimal(const AAnimal& other) {
    this->type = other.type;
    std::cout << "Un Animal a été cloné" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

