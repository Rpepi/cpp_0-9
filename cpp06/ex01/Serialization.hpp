/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:04:55 by pepi              #+#    #+#             */
/*   Updated: 2025/03/20 13:15:30 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include <iostream>
# include <string>
# include <iomanip>

typedef struct Data {
    std::string name;
    int         age;
    Data        *next;
}  Data;

class Serialization {
    private:
        Serialization();
        Serialization(const Serialization& other); // Copy constructor
        Serialization& operator=(const Serialization& other); // Copy assignment operator
        ~Serialization();
    public:
        static unsigned long serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif