/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:14:01 by pepi              #+#    #+#             */
/*   Updated: 2025/03/24 11:56:10 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include<iterator>

class Span {
    private:
        std::vector<unsigned int> span;
        unsigned int size;
    public:
        Span();
        Span(const unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();
        void addNumber(unsigned int N);
        template <typename Iterator>
        void addNumbers(Iterator begin, Iterator end)
        {
            std::vector<unsigned int> temp(begin, end);
            if (span.size() + temp.size() > size) {
                throw Spanisfull();
            }
            span.insert(span.end(), temp.begin(), temp.end());
        }
        unsigned int  shortestSpan();
        unsigned int longestSpan();
        class Spanisfull : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Span is full";
                }
        };
        class Spanistooshort : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Span is too short";
                }
        };


};


#endif