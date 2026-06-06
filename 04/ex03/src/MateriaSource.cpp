/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 15:33:06 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/06 16:04:29 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        materia_[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    for (int i = 0; i < 4; i++)
        materia_[i] = other.materia_[i];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
            materia_[i] = other.materia_[i]->clone();
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for(int i = 0; i < 4; i++)
        delete materia_[i];
}

void MateriaSource::learnMateria(AMateria *m)
{
    if (!m)
        return;

    for (int i = 0; i < 4; i++)
    {
        if (materia_[i] == NULL)
        {
            materia_[i] = m;
            return;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for(int i = 0; i < 4; i++)
    {
        if(materia_[i] && materia_[i]->getType() == type)
            return materia_[i]->clone();
    }
    return NULL;
}