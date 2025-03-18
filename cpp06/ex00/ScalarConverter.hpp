/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:07:28 by pepi              #+#    #+#             */
/*   Updated: 2025/03/18 10:36:47 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <cctype>
#include <iomanip>
#include <stdexcept>

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
        
        static bool isChar(const std::string& literal);
        static bool isPseudoLiteral(const std::string& literal);
        static bool isFloat(const std::string& literal);
        static bool isDouble(const std::string& literal);
        static bool isInt(const std::string& literal);
        
        static void convertFromChar(const std::string& literal);
        static void convertFromPseudoLiteral(const std::string& literal);
        static void convertFromNumeric(const std::string& literal);

    public:
        static void convert(const std::string& literal);
};

#endif