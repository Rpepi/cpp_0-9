/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:11:48 by rpepi             #+#    #+#             */
/*   Updated: 2025/03/21 12:40:12 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bitcoin::bitcoin() {
    loadDatabase();
}

bitcoin::bitcoin(const bitcoin& other) : database(other.database) {}

bitcoin& bitcoin::operator=(const bitcoin& other) {
    if (this != &other)
        database = other.database;
    return *this;
}

bitcoin::~bitcoin() {}

std::string bitcoin::trim(const std::string& str) const {
    size_t first = str.find_first_not_of(" \t");
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(" \t");
    return str.substr(first, last - first + 1);
}

bool bitcoin::isValidDate(const std::string& date) const {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    
    if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;
        
    return true;
}

bool bitcoin::isValidValue(const double value) const {
    return value >= 0 && value <= 1000;
}

void bitcoin::loadDatabase(void) {
    std::ifstream file("data.csv");
    if (!file.is_open())
        throw FileNotFoundException();
        
    std::string line;
    std::getline(file, line); // Skip header
    
    while (std::getline(file, line)) {
        size_t comma = line.find(',');
        if (comma != std::string::npos) {
            std::string date = trim(line.substr(0, comma));
            double value = std::atof(trim(line.substr(comma + 1)).c_str());
            if (isValidDate(date))
                database[date] = value;
        }
    }
    file.close();
}

void bitcoin::getprice(const std::string& input) {
    std::ifstream file(input.c_str());
    if (!file.is_open())
        throw FileNotFoundException();
        
    std::string line;
    std::getline(file, line); // Skip header
    
    while (std::getline(file, line)) {
        size_t pipe = line.find('|');
        if (pipe == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        std::string date = trim(line.substr(0, pipe));
        std::string value_str = trim(line.substr(pipe + 1));
        
        if (!isValidDate(date)) {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        
        double value = std::atof(value_str.c_str());
        if (!isValidValue(value)) {
            if (value < 0)
                std::cout << "Error: not a positive number." << std::endl;
            else
                std::cout << "Error: too large a number." << std::endl;
            continue;
        }
        
        std::map<std::string, double>::iterator it = database.lower_bound(date);
        if (it == database.begin() && date < it->first) {
            std::cout << "Error: no data available for this date." << std::endl;
            continue;
        }
        if (it == database.end() || date < it->first)
            --it;
            
        std::cout << date << " => " << value << " = " << value * it->second << std::endl;
    }
    file.close();
}