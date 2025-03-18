/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:07:21 by pepi              #+#    #+#             */
/*   Updated: 2025/03/18 10:33:07 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>  // Pour std::atof
#include <iostream>
#include <iomanip>  // Pour std::fixed et std::setprecision

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
    return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
}

bool ScalarConverter::isPseudoLiteral(const std::string& literal) {
    return (literal == "nan" || literal == "nanf" ||
            literal == "+inf" || literal == "+inff" ||
            literal == "-inf" || literal == "-inff");
}

bool ScalarConverter::isFloat(const std::string& literal) {
    if (literal.empty()) return false;
    return (literal[literal.length() - 1] == 'f' && literal.find('.') != std::string::npos);
}

bool ScalarConverter::isDouble(const std::string& literal) {
    if (literal.empty()) return false;
    return (literal.find('.') != std::string::npos);
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
    char c = literal[1];
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
    try {
        double value;
        if (isFloat(literal)) {
            value = std::atof(literal.substr(0, literal.length() - 1).c_str());
        } else {
            value = std::atof(literal.c_str());  // atof = string -> double
        }

        // Conversion et affichage char
        if (value >= 32 && value <= 126) {
            std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
        } else if (value >= 0 && value <= 127) {
            std::cout << "char: Non displayable" << std::endl;
        } else {
            std::cout << "char: impossible" << std::endl;
        }

        // Conversion et affichage int
        if (value > std::numeric_limits<int>::max() || 
            value < std::numeric_limits<int>::min() ||
            std::isnan(value)) {
            std::cout << "int: impossible" << std::endl;
        } else {
            std::cout << "int: " << static_cast<int>(value) << std::endl;
        }

        // Affichage float et double
        std::cout << std::fixed << std::setprecision(1);
        if (value > std::numeric_limits<float>::max() || 
            value < -std::numeric_limits<float>::max()) {
            std::cout << "float: impossible" << std::endl;
        } else {
            std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
        }
        std::cout << "double: " << value << std::endl;

    } catch (const std::exception& e) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
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
