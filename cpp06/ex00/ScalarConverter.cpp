/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:07:21 by pepi              #+#    #+#             */
/*   Updated: 2025/03/21 12:54:40 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iostream>
#include <iomanip>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isChar(const std::string& literal) {
    // Si la chaîne fait exactement 1 caractère et est affichable
    return (literal.length() == 1 && isprint(literal[0]));
}

bool ScalarConverter::isPseudoLiteral(const std::string& literal) {
    return (literal == "nan" || literal == "nanf" ||
            literal == "+inf" || literal == "+inff" ||
            literal == "-inf" || literal == "-inff");
}

bool ScalarConverter::isFloat(const std::string& literal) {
    if (literal.empty()) return false;
    
    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
        return true;
        
    if (literal[literal.length() - 1] != 'f')
        return false;
        
    std::string numPart = literal.substr(0, literal.length() - 1);
    char* endPtr;
    strtof(numPart.c_str(), &endPtr);
    return (*endPtr == '\0');
}

bool ScalarConverter::isDouble(const std::string& literal) {
    if (literal.empty()) return false;
    
    if (literal == "nan" || literal == "+inf" || literal == "-inf")
        return true;
        
    char* endPtr;
    strtod(literal.c_str(), &endPtr);
    return (*endPtr == '\0');
}

bool ScalarConverter::isInt(const std::string& literal) {
    if (literal.empty()) return false;
    
    size_t start = (literal[0] == '-' || literal[0] == '+') ? 1 : 0;
    for (size_t i = start; i < literal.length(); ++i) {
        if (!isdigit(literal[i])) {
            return false;
        }
    }
    return true;
}

void ScalarConverter::convertFromChar(const std::string& literal) {
    char c = literal[0];
    
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::convertFromPseudoLiteral(const std::string& literal) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    
    if (literal == "nan" || literal == "nanf") {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    } else {
        bool isNegative = (literal[0] == '-');
        std::cout << "float: " << (isNegative ? "-" : "+") << "inff" << std::endl;
        std::cout << "double: " << (isNegative ? "-" : "+") << "inf" << std::endl;
    }
}

void ScalarConverter::convertFromNumeric(const std::string& literal) {
    double value;
    if (isFloat(literal)) {
        value = strtod(literal.substr(0, literal.length() - 1).c_str(), NULL);
    } else {
        value = strtod(literal.c_str(), NULL);
    }

    if (value >= 0 && value <= 127) {
        if (value >= 32 && value <= 126)
            std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: impossible" << std::endl;
    }

    if (value > INT_MAX || value < INT_MIN || isnan(value)) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    }

    std::cout << std::fixed << std::setprecision(1);
    
    if (isnan(value)) {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    } else if (isinf(value)) {
        std::cout << "float: " << (value > 0 ? "+" : "-") << "inff" << std::endl;
        std::cout << "double: " << (value > 0 ? "+" : "-") << "inf" << std::endl;
    } else {
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
        std::cout << "double: " << value << std::endl;
    }
}

void ScalarConverter::convert(const std::string& literal) {
    if (literal.empty()) {
        std::cout << "Error: empty input" << std::endl;
        return;
    }
    if (isChar(literal)) {
        convertFromChar(literal);
    }
    else if (isPseudoLiteral(literal)) {
        convertFromPseudoLiteral(literal);
    }
    else {
        convertFromNumeric(literal);
    }
}
