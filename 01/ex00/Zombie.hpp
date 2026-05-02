/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martinmust <martinmust@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 16:11:06 by martinmust        #+#    #+#             */
/*   Updated: 2026/05/02 19:08:28 by martinmust       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>


class Zombie{

private:
    std::string name_;

public:
    Zombie(std::string name);
    ~Zombie(void);
    void announce(void);

};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif