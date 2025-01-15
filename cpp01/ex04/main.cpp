/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:58:37 by pepi              #+#    #+#             */
/*   Updated: 2025/01/15 13:04:29 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    FileReplacer replacer(argv[1], argv[2], argv[3]);
    if (!replacer.processFile()) {
        std::cout << "Erreur dans le traitement du fichier." << std::endl;
        return (1);
    }
    else
    {
        std::cout << "Fichier traité avec succès." << std::endl;
    }
    return 0;
}