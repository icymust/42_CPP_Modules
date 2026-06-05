/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 15:56:56 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/05 18:18:52 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Cat.hpp"
#include "../lib/Dog.hpp"
#include <iostream>

int main()
{
    std::cout << "\n--- Abstract Animal test ---" << std::endl;

    Animal *dog = new Dog();
    Animal *cat = new Cat();

    std::cout << dog->getType() << std::endl;
    std::cout << cat->getType() << std::endl;

    dog->makeSound();
    cat->makeSound();

    delete dog;
    delete cat;

    std::cout << "\n--- Animal array test ---" << std::endl;

    Animal *animals[4];

    for (int i = 0; i < 2; i++)
        animals[i] = new Dog();

    for (int i = 2; i < 4; i++)
        animals[i] = new Cat();

    for (int i = 0; i < 4; i++)
        animals[i]->makeSound();

    for (int i = 0; i < 4; i++)
        delete animals[i];

    return 0;
}