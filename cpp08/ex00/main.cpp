/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:59:37 by pepi              #+#    #+#             */
/*   Updated: 2025/03/24 11:51:44 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int main(void)
{
    std::vector<int> container;
    container.push_back(1);
    container.push_back(2);
    container.push_back(3);
    container.push_back(4);

    ::easyfind(container, 8);
    ::easyfind(container, 2);
    ::easyfind(container, 10);
    
    return 0;
}