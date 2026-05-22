/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 14:45:59 by mmustone          #+#    #+#             */
/*   Updated: 2026/05/22 16:33:03 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"

int main(int ac, char **av){
    if(ac !=4 )
        return(1);
    File file;
    if(file.setArgs(av) == 1)
        return(1);
    if(file.replace() == 1)
        return(1);
    std::cout << "GOOD" << std::endl;
    return(0);
}

// 1. Проверить argc
// 2. Проверить, что s1 не пустой
// 3. Сохранить filename/s1/s2
// 4. Открыть input file
// 5. Создать output file filename + ".replace"
// 6. Читать и заменять