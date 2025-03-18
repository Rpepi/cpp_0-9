/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:04:58 by pepi              #+#    #+#             */
/*   Updated: 2025/03/18 10:55:00 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

Serialization::Serialization() {}

Serialization::Serialization(const Serialization& other) {
    (void)other;
}

Serialization& Serialization::operator=(const Serialization& other) {
    (void)other;
    return *this;
}

Serialization::~Serialization() {}

unsigned long Serialization::serialize(Data* ptr)
{
    return reinterpret_cast<unsigned long>(ptr);
}

Data* Serialization::deserialize(unsigned long raw)
{
    return reinterpret_cast<Data *>(raw);
}