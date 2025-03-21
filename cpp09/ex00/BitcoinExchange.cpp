/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:11:48 by rpepi             #+#    #+#             */
/*   Updated: 2025/03/21 12:34:02 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bitcoin::bitcoin() {};

bitcoin::~bitcoin() {};

bitcoin::bitcoin(const bitcoin& other) {
    (void)other;
}

bitcoin& bitcoin::operator=(const bitcoin& other) {
    if (this != &other) {
    }
    return *this;
}

void bitcoin::getprice(std::string& input)
{
    std::ifstream file(input.c_str());
    if (!file)
    {
        std::cerr << "Impossible d'ouvrir le fichier : " << &file << std::endl;
        return;
    }

    
}