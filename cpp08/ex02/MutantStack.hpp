/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:51:41 by pepi              #+#    #+#             */
/*   Updated: 2025/03/06 15:38:04 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <deque>
#include <iterator>
#include <string>
#include <stack>
#include <list>


template<typename T>
class MutantStack {
private:
    std::deque<T> stack;
public:
    typedef typename std::deque<T>::iterator iterator;

    void push(const T& value) {
        stack.push_back(value);
    }

    void pop(){
        stack.pop_back();
    }
    
    T top() const {
        return stack.back();
    }

    size_t size() const {
        return stack.size();
    }

    iterator begin() {
        return stack.begin();
    }

    iterator end() {
        return stack.end();
    }
};

#endif