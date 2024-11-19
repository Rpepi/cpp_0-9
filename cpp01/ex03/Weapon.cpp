/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:23:50 by pepi              #+#    #+#             */
/*   Updated: 2024/11/14 14:41:36 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string& Weapon::getType() const 
{ 
    return this->type; 
}

void Weapon::setType(std::string type)
{
    this->type = type;
}

Weapon::Weapon(const std::string& type)
{
    this->type = type;
}