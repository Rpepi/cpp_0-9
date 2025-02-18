/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:53:46 by pepi              #+#    #+#             */
/*   Updated: 2025/02/18 11:07:26 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"


int main()
{
const Animal* j = new Dog();
const Animal* i = new Cat();
delete j;
delete i;
system("leaks ex01");
return 0;
}

// int main()
// {
//  	const Animal *animals[4];

// 	for(int i = 0; i < 2; i++)
// 	{
// 		animals[i] = new Cat();
// 		std::cout << "\n";
// 	}

// 	for(int i = 2; i < 4; i++)
// 	{
// 		animals[i] = new Dog();
// 		std::cout << "\n";
// 	}

// 	for(int i = 0; i < 4; i++)
// 	{
// 		delete animals[i];
// 		std::cout << "\n";
// 	}

//     return 0;
// }

/*
int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete j;
    delete i;
    return 0;
}
*/