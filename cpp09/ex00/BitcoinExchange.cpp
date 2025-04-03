/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:11:48 by rpepi             #+#    #+#             */
/*   Updated: 2025/04/03 12:19:46 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bitcoin::bitcoin(const std::string csvFile) {
    loadDatabase(csvFile);
}

bitcoin::bitcoin(const bitcoin& other) : database(other.database) {}

bitcoin& bitcoin::operator=(const bitcoin& other) {
    if (this != &other)
        database = other.database;
    return *this;
}

bitcoin::~bitcoin() {}

std::string bitcoin::trim(const std::string str) const {
    size_t first = str.find_first_not_of(" \t");
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(" \t");
    return str.substr(first, last - first + 1);
}

bool bitcoin::isValidDate(const std::string date) const {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    
    if (year < 2005 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        daysInMonth[1] = 29;
    
    if (day > daysInMonth[month - 1])
        return false;
        
    return true;
}

void bitcoin::loadDatabase(const std::string filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw FileNotFoundException();
    }
        
    std::string line;
    std::getline(file, line); // Skip header
    
    if (line != "date | value") {
        std::cerr << "Error: invalid CSV format in " << filename << std::endl;
        file.close();
        throw FileNotFoundException();
    }
    
    while (std::getline(file, line)) {
        size_t pipe = line.find('|');
        if (pipe == std::string::npos) {
            std::cerr << "Error: invalid line format in CSV => " << line << std::endl;
            continue;
        }
        
        std::string date = trim(line.substr(0, pipe));
        std::string value_str = trim(line.substr(pipe + 1));
        
        if (!isValidDate(date)) {
            std::cerr << "Error: invalid date in CSV => " << date << std::endl;
            continue;
        }
        
        char* endptr;
        double value = std::strtod(value_str.c_str(), &endptr);
        if (*endptr != '\0' || value < 0) {
            std::cerr << "Error: invalid value in CSV => " << value_str << std::endl;
            continue;
        }
        
        database[date] = value;
    }
    file.close();
    
    if (database.empty()) {
        std::cerr << "Error: no valid data found in CSV file " << filename << std::endl;
        throw FileNotFoundException();
    }
}

void bitcoin::getprice(const std::string input) {
    std::ifstream file(input.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        throw FileNotFoundException();
    }
        
    std::string line;
    std::getline(file, line); // Skip header
    
    if (line != "date | value") {
        std::cerr << "Error: invalid file format." << std::endl;
        file.close();
        throw FileNotFoundException();
    }
    
    while (std::getline(file, line)) {
        size_t pipe = line.find('|');
        if (pipe == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        std::string date = trim(line.substr(0, pipe));
        std::string value_str = trim(line.substr(pipe + 1));
        
        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        
        char* endptr;
        double value = std::strtod(value_str.c_str(), &endptr);
        if (*endptr != '\0') {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        
        if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        
        std::map<std::string, double>::iterator it = database.lower_bound(date);
        if (it == database.begin() && date < it->first) {
            std::cerr << "Error: no data available for this date." << std::endl;
            continue;
        }
        if (it == database.end() || date < it->first)
            --it;
            
        std::cout << date << " => " << value << " = " << value * it->second << std::endl;
    }
    file.close();
}