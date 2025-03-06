/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:20:04 by pepi              #+#    #+#             */
/*   Updated: 2025/03/06 15:24:41 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    try {
        unsigned int arr[] = {3, 10, 6, 15, 1};
        std::vector<unsigned int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
        Span sp = Span(7);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        sp.addNumbers(vec.begin(), vec.end());
    }
    catch (const Span::Spanisfull& e) {
        std::cerr << "Exception attrapée : " << e.what() << std::endl;
    }
    catch (const Span::Spanistooshort& e) {
        std::cerr << "Exception attrapée : " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception inattendue : " << e.what() << std::endl;
    }

    return 0;
}