/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:53:39 by pepi              #+#    #+#             */
/*   Updated: 2024/11/15 13:53:41 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: ./harl [DEBUG/INFO/WARNING/ERROR]" << std::endl;
        return 1;
    }

    std::string input(argv[1]);
    if (input != "DEBUG" && input != "INFO" && input != "WARNING" && input != "ERROR") {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return 1;
    }

    Harl harl;
    harl.complain(input);
    return 0;
}