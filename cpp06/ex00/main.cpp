/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:07:32 by pepi              #+#    #+#             */
/*   Updated: 2025/03/18 10:36:35 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "ERROR: no arguments or more than 1" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return (0);
}
//max int 2147483647
//min int -2147483648
//min float -3.40282e+38
//max float 3.40282e+38
//max double 1.79769e+308
//min double -1.79769e+308