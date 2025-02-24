/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:04:58 by pepi              #+#    #+#             */
/*   Updated: 2025/02/24 18:35:29 by pepi             ###   ########.fr       */
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

uintptr_t Serialization::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serialization::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}