/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 14:39:17 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/05 18:12:08 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
protected:
    std::string type_;

public:
    Animal();
    Animal(std::string type);
    Animal(const Animal &other);
    Animal &operator=(const Animal &other);
    virtual ~Animal();

    virtual void makeSound() const = 0;
    std::string getType() const;
};

#endif
