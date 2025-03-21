/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:16:52 by rpepi             #+#    #+#             */
/*   Updated: 2025/03/21 12:24:50 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        bitcoin btc;
        
        btc.getprice(argv[1]);
    }
    else
        std::cout << "Error: invalid number of arguments" << std::endl;
}