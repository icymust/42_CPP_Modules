/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 15:56:56 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/05 17:04:05 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Cat.hpp"
#include "../lib/Dog.hpp"
#include <iostream>

int main()
{
    std::cout << "\n--- Animal array test ---" << std::endl;

    Animal *animals[4];

    for (int i = 0; i < 2; i++)
        animals[i] = new Dog();

    for (int i = 2; i < 4; i++)
        animals[i] = new Cat();

    std::cout << "\n--- Sound test ---" << std::endl;

    for (int i = 0; i < 4; i++)
        animals[i]->makeSound();

    std::cout << "\n--- Delete through Animal* test ---" << std::endl;

    for (int i = 0; i < 4; i++)
        delete animals[i];

    std::cout << "\n--- Dog copy constructor test ---" << std::endl;

    Dog dog1;
    Dog dog2(dog1);

    std::cout << "\n--- Dog assignment operator test ---" << std::endl;

    Dog dog3;
    dog3 = dog1;

    std::cout << "\n--- Cat copy constructor test ---" << std::endl;

    Cat cat1;
    Cat cat2(cat1);

    std::cout << "\n--- Cat assignment operator test ---" << std::endl;

    Cat cat3;
    cat3 = cat1;

    std::cout << "\n--- End of main ---" << std::endl;

    return 0;
}