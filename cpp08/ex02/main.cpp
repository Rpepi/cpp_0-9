/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:36:26 by pepi              #+#    #+#             */
/*   Updated: 2025/03/06 15:42:34 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main(){
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;  // Affiche 17
    mstack.pop();
    std::cout << mstack.size() << std::endl;  // Affiche 1
    std::cout << "------" << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << "------" << std::endl;

    std::list<int> s(mstack.begin(), mstack.end());
    for (std::list<int>::iterator it = s.begin(); it != s.end(); ++it) {
        std::cout << *it << std::endl;
    }
    return 0;
}
