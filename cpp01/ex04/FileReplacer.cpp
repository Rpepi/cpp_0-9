/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:06:15 by pepi              #+#    #+#             */
/*   Updated: 2025/01/15 13:37:39 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"

FileReplacer::FileReplacer(std::string filename, std::string s1, std::string s2) : filename(filename), s1(s1), s2(s2)
{
	this->filename = filename;
	this->s1 = s1;
	this->s2 = s2;
}

std::string FileReplacer::replaceLine(std::string line) 
{
	std::string::size_type pos = 0;
	std::string result;

	pos = line.find(s1);
	while (pos != std::string::npos)
	{
		std::string first_part = line.substr(0, pos);
		std::string second_part = line.substr(pos + s1.length(), line.length());
			
		result = first_part + s2 + second_part;
		pos = line.find(s1, pos + s2.length());
	} 
	return (result);
}

bool FileReplacer::processFile() 
{
	std::ifstream inputFile(filename);
	if (!inputFile.is_open()) 
	{
		std::cerr << "Erreur: Impossible d'ouvrir le fichier source" << std::endl;
		return false;
	}
	std::string outFilename = filename + ".replace";
	std::ofstream outputFile(outFilename);
	if (!outputFile.is_open()) 
	{
		std::cerr << "Erreur: Impossible de créer le fichier de sortie" << std::endl;
		inputFile.close();
		return false;
	}
	std::string line;
	while (std::getline(inputFile, line)) 
	{
		std::string modifiedLine = replaceLine(line);
		outputFile << modifiedLine;
		if (!inputFile.eof()) 
		{
			outputFile << std::endl;
		}
	}
	inputFile.close();
	outputFile.close();
	return true;
}