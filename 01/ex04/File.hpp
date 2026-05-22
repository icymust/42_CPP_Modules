/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 15:07:00 by mmustone          #+#    #+#             */
/*   Updated: 2026/05/22 16:32:57 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>
#include <string>
#include <fstream>

class File
{
private:
    std::string filename_;
    std::string s1_;
    std::string s2_;
public:
    int setArgs(char **av);
    int replace();
};

#endif