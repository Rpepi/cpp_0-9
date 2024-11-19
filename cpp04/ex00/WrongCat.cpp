/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:56:46 by pepi              #+#    #+#             */
/*   Updated: 2024/11/19 12:13:53 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
    this->type = "WrongCat";
    std::cout << "Un WrongCat est apparu, mais quelque chose cloche..." << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "Un WrongCat a disparu, c'était peut-être mieux ainsi" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "Miaou... mais en incorrect!" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    this->type = other.type;
    std::cout << "Un WrongCat a été cloné" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other) {
        WrongAnimal::operator=(other);
        this->type = other.type;
    }
    return *this;
} 