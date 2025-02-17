/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:53:46 by pepi              #+#    #+#             */
/*   Updated: 2024/11/19 12:29:52 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    //const AAnimal* meta = new AAnimal();
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    
    // Test des sons
    std::cout << "\nTest des sons :" << std::endl;
    j->makeSound();
    i->makeSound();
    
    // Test du type
    std::cout << "\nTest des types :" << std::endl;
    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;
    
    // Nettoyage
    delete j;
    delete i;
    
    // Test avec un tableau
    std::cout << "\nTest avec tableau :" << std::endl;
    AAnimal* animals[4];
    for(int k = 0; k < 4; k++)
    {
        if(k < 2)
            animals[k] = new Dog();
        else
            animals[k] = new Cat();
    }
    
    for(int k = 0; k < 4; k++)
        delete animals[k];
    
    return 0;
}


