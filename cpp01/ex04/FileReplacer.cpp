/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:06:15 by pepi              #+#    #+#             */
/*   Updated: 2025/01/23 13:29:44 by rpepi            ###   ########.fr       */
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
	if (s1.empty()) {
		return line; // Si s1 est vide, retournez la ligne inchangée
	}
	std::string::size_type pos = 0;
	std::string result = line;

	pos = result.find(s1);
	while (pos != std::string::npos)
	{
		result.replace(pos, s1.length(), s2);
		pos = result.find(s1, pos + s2.length());
	} 
	return result;
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