/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:20:43 by pepi              #+#    #+#             */
/*   Updated: 2025/01/15 11:35:39 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>

int main() 
{
    PhoneBook phoneBook;
    std::string command;

    while (true) 
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command))
            break ;
        if (command == "ADD") 
            phoneBook.addContact();
        else if (command == "SEARCH") 
            phoneBook.searchContacts();
        else if (command == "EXIT")
            break ;
        else
            std::cout << "Invalid command. Please try again." << std::endl;
    }
    return 0;
}
