/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:56:09 by pepi              #+#    #+#             */
/*   Updated: 2024/11/02 13:41:59 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

PhoneBook::PhoneBook() : currentIndex(0), totalContacts(0) {}

void PhoneBook::addContact() 
{
    Contact contact;
    std::string input;

    std::cout << "Enter first name: ";
    std::getline(std::cin, input);
    contact.setFirstName(input);

    std::cout << "Enter last name: ";
    std::getline(std::cin, input);
    contact.setLastName(input);

    std::cout << "Enter nickname: ";
    std::getline(std::cin, input);
    contact.setNickname(input);

    std::cout << "Enter phone number: ";
    std::getline(std::cin, input);
    contact.setPhoneNumber(input);

    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, input);
    contact.setDarkestSecret(input);

    // Ajouter le contact au répertoire
    contacts[currentIndex] = contact;
    currentIndex = (currentIndex + 1) % MAX_CONTACTS; // Remplace le plus ancien si nécessaire
    if (totalContacts < MAX_CONTACTS) ++totalContacts;
}

void PhoneBook::searchContacts() const 
{
    // Affichage de l'entête de la liste
    std::cout << std::setw(10) << "Index" << "|" 
              << std::setw(10) << "First name" << "|"
              << std::setw(10) << "Last name" << "|" 
              << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < totalContacts; ++i) 
    {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << (contacts[i].getFirstName().size() > 10 ? contacts[i].getFirstName().substr(0, 9) + "." : contacts[i].getFirstName()) << "|";
        std::cout << std::setw(10) << (contacts[i].getLastName().size() > 10 ? contacts[i].getLastName().substr(0, 9) + "." : contacts[i].getLastName()) << "|";
        std::cout << std::setw(10) << (contacts[i].getNickname().size() > 10 ? contacts[i].getNickname().substr(0, 9) + "." : contacts[i].getNickname()) << std::endl;
    }
    std::cout << "Enter index of contact to display: ";
    int index;
    std::cin >> index;
    if (std::cin.fail() || index < 0 || index >= totalContacts) 
    {
        std::cout << "Invalid index." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // permet d'ignorer les caractères invalides jusqu'à \n
    } 
    else 
        displayContact(index);
}

void PhoneBook::displayContact(int index) const 
{
    std::cout << "First name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << contacts[index].getDarkestSecret() << std::endl;
}
