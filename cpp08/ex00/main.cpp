/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:59:37 by pepi              #+#    #+#             */
/*   Updated: 2025/03/06 12:08:25 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
    std::array<int, 4> container = {1, 2, 3, 4};


    ::easyfind(container, 8);
    ::easyfind(container, 2);
    ::easyfind(container, 10);
    
}