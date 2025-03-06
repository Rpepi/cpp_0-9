/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:36:33 by pepi              #+#    #+#             */
/*   Updated: 2025/03/06 12:11:51 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define TEMPLATE_HPP

#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>

template <typename T> int easyfind(T& container, int i)
{
    for (int j = 0; container[j] != '\0'; j++)
    {
        if (i == container[j])
        {
            std::cout << "occurence trouvée a l'index " << j << std::endl;
            return (0);
        }
    }
    std::cout << "occurence non trouvée..." << std::endl;
    return (1);
}

#endif