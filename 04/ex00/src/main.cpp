/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 15:56:56 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/05 13:41:45 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Cat.hpp"
#include "../lib/Dog.hpp"
#include "../lib/WrongCat.hpp"
#include <iostream>

int main()
{
    std::cout << "----- Animals -----" << std::endl;
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    std::cout << "\n----- Wrong Animals -----" << std::endl;
    const WrongAnimal *k = new WrongCat();
    std::cout << k->getType() << " " << std::endl;
    k->makeSound();

    std::cout << "\n----- Clean up -----" << std::endl;
    delete meta;
    delete j;
    delete i;
    delete k;
    
    return 0;
}
