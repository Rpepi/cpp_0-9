/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:14:46 by pepi              #+#    #+#             */
/*   Updated: 2024/11/02 13:38:26 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

void Contact::setFirstName(const std::string& firstName)
{
    this->firstName = firstName;
}

void Contact::setLastName(const std::string& lastName)
{
    this->lastName = lastName;
}

void Contact::setNickname(const std::string& nickname)
{
    this->nickname = nickname;
}

void Contact::setPhoneNumber(const std::string& phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string& darkestSecret)
{
    this->darkestSecret = darkestSecret;
}

const std::string& Contact::getFirstName() const
{
    return firstName;
}

const std::string& Contact::getLastName() const
{
    return lastName;
}

const std::string& Contact::getNickname() const
{
    return nickname;
}

const std::string& Contact::getPhoneNumber() const
{
    return phoneNumber;
}
const std::string& Contact::getDarkestSecret() const
{
    return darkestSecret;
}
