/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 16:49:00 by mmustone          #+#    #+#             */
/*   Updated: 2026/05/15 16:52:01 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA.HPP
#define HUMANA.HPP

#include "Weapon.hpp"

class HumanA
{
private:
    Weapon gun;
public:
    void attack();
};

#endif