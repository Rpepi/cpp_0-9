/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:53:18 by pepi              #+#    #+#             */
/*   Updated: 2024/11/19 12:19:18 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
    this->type = "Cat";
    this->brain = new Brain();
    std::cout << "Un chat est né avec un cerveau" << std::endl;
}


Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        delete this->brain;
        this->brain = new Brain(*other.brain);
        this->type = other.type;
    }
    return *this;
}

Cat::~Cat() {
    delete this->brain;
    std::cout << "Un chat nous a quittés, son cerveau aussi" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Miaou! Miaou!" << std::endl;
}
