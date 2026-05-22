/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 15:21:34 by mmustone          #+#    #+#             */
/*   Updated: 2026/05/22 18:41:44 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"

int File::setArgs(char **av){
    filename_ = av[1];
    s1_ = av[2];
    s2_ = av[3];

    if(filename_.empty() || s1_.empty() || s2_.empty())
        return(1);
    return(0);
}

int File::replace(){
    
    std::string outputName = filename_ + ".replace";

    // открыть файл для чтения
    std::ifstream inputFile(filename_.c_str());
    if(!inputFile){
        std::cout << "Error: Could not open the file!" << std::endl;
        return(1);
    }
    
    // открыть/создать файл для записи
    std::ofstream outputFile(outputName.c_str());
    if(!outputFile){
        std::cout << "Error: Could not create output file!" << std::endl;
        return(1);
    }

    std::string line;

    while (std::getline(inputFile, line))
    {
        std::size_t pos = 0;
        std::size_t found;

        while ((found = line.find(s1_, pos)) != std::string::npos)
        {
            outputFile << line.substr(pos, found - pos);
            outputFile << s2_;
            pos = found + s1_.length();
        }

        outputFile << line.substr(pos);

        if (!inputFile.eof())
            outputFile << std::endl;
    }
    
    return(0);
}