/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 16:44:56 by mmustone          #+#    #+#             */
/*   Updated: 2026/05/15 16:55:33 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON.HPP
#define WEAPON.HPP

#include <iostream>
#include <string>

class Weapon
{
private:
    std::string type;
public:
    std::string getType();
    void setType(std::string newType);
};

#endif