/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 11:41:57 by rpepi             #+#    #+#             */
/*   Updated: 2025/03/21 12:31:09 by rpepi            ###   ########.fr       */
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

    public:
        bitcoin();
        bitcoin(const bitcoin& other);
        bitcoin& operator=(const bitcoin& other);
        ~bitcoin();
        void getprice(std::string& input);
        
        
};


#endif