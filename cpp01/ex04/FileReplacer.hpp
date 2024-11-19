/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:00:58 by pepi              #+#    #+#             */
/*   Updated: 2024/11/15 13:35:51 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEREPLACER_HPP
#define FILEREPLACER_HPP

#include <string>
#include <iostream>
#include <fstream>

class FileReplacer
{
    private:
        std::string filename;
        std::string s1;
        std::string s2;
    public:
        FileReplacer(std::string filename, std::string s1, std::string s2);
        bool processFile();
        std::string replaceLine(std::string line);
        
};

#endif
