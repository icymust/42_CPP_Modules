/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 16:51:47 by mmustone          #+#    #+#             */
/*   Updated: 2026/05/15 16:52:04 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB.HPP
#define HUMANB.HPP

#include "Weapon.hpp"

class HumanB
{
private:
    Weapon gun;
public:
    void attack();
};

#endif