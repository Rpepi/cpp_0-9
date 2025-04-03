/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 11:41:57 by rpepi             #+#    #+#             */
/*   Updated: 2025/04/03 12:11:43 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <cstdlib>
# include <string>
# include <ctime>
# include <cstring>

class bitcoin {
    private:
        std::map<std::string, double> database;
        bool isValidDate(const std::string date) const;
        void loadDatabase(const std::string filename);
        std::string trim(const std::string str) const;

    public:
        bitcoin(const std::string csvFile);
        bitcoin(const bitcoin& other);
        bitcoin& operator=(const bitcoin& other);
        ~bitcoin();
        void getprice(const std::string input);
        class InvalidDateException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Error: invalid date format";
                }
        };
        class InvalidValueException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Error: invalid value";
                }
        };
        class FileNotFoundException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Error: could not open file";
                }
        };
};


#endif