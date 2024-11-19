/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:14:36 by pepi              #+#    #+#             */
/*   Updated: 2024/11/02 13:35:40 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact 
{
    public:
        void setFirstName(const std::string& firstName);
        void setLastName(const std::string& lastName);
        void setNickname(const std::string& nickname);
        void setPhoneNumber(const std::string& phoneNumber);
        void setDarkestSecret(const std::string& darkestSecret);

        const std::string& getFirstName() const;
        const std::string& getLastName() const;
        const std::string& getNickname() const;
        const std::string& getPhoneNumber() const;
        const std::string& getDarkestSecret() const;

    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;
};

#endif
