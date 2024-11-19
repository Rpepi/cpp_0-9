/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:56:11 by pepi              #+#    #+#             */
/*   Updated: 2024/11/02 13:35:32 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#define MAX_CONTACTS 8

class PhoneBook 
{
    public:
        PhoneBook();
        void addContact();
        void searchContacts() const;
        void displayContact(int index) const;

    private:
        Contact contacts[MAX_CONTACTS];
        int currentIndex;
        int totalContacts;
};

#endif
