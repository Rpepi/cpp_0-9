/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:36:33 by pepi              #+#    #+#             */
/*   Updated: 2025/03/24 11:51:44 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>

template <typename T> int easyfind(T& container, int i)
{
    typename T::iterator it = std::find(container.begin(), container.end(), i);
    if (it != container.end())
    {
        std::cout << "occurence trouvée a l'index " << std::distance(container.begin(), it) << std::endl;
        return (0);
    }
    std::cout << "occurence non trouvée..." << std::endl;
    return (1);
}

#endif