/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:56:56 by pepi              #+#    #+#             */
/*   Updated: 2024/11/19 12:15:16 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("") {
    std::cout << "Un WrongAnimal est apparu de nulle part" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "Un WrongAnimal a disparu mystérieusement" << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "* Son étrange et incorrect *" << std::endl;
}

std::string WrongAnimal::getType() const {
    return this->type;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    this->type = other.type;
    std::cout << "Un WrongAnimal a été cloné" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
} 