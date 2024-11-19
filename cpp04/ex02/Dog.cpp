/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:53:29 by pepi              #+#    #+#             */
/*   Updated: 2024/11/19 12:24:52 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal() {
    this->type = "Dog";
    this->brain = new Brain();
    std::cout << "Un chien est né avec un cerveau" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other) {
    this->brain = new Brain(*other.brain);
    this->type = other.type;
    std::cout << "Un chien a été cloné" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        delete this->brain;
        this->brain = new Brain(*other.brain);
        this->type = other.type;
    }
    return *this;
}

Dog::~Dog() {
    delete this->brain;
    std::cout << "Un chien nous a quittés, son cerveau aussi" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}
