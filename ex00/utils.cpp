/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:00:24 by frromero          #+#    #+#             */
/*   Updated: 2025/12/15 22:58:16 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cctype>
#include "ScalarConverter.hpp"
#include <algorithm> 
#include <iomanip>

void charConvert(std::string strNumber)
{
    char c = strNumber[0];
    int intNumber = static_cast<int>(c);    
    float floatNumber = static_cast<float>(c);
    double doubleNumber = static_cast<double>(c);

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "char: '" << strNumber << "'" << std::endl;
    std::cout << "int: " << intNumber  << std::endl;    
    std::cout << "float: " << floatNumber  << "f" <<std::endl;
    std::cout << "double: " << doubleNumber  <<std::endl;
}

void specialConvert(std::string strNumber)
{
    std::cout << "char: impossible"  << std::endl;
    std::cout << "int: impossible"  << std::endl;  
    if (strNumber == "nan" || strNumber == "nanf")
    {
         std::cout << "float: nanf"  << std::endl;
         std::cout << "double: naf"  << std::endl; 
    }

}


int getType(std::string strNumber)
{
    // SPECIAL
    if (strNumber == "-inff" || strNumber == "+inff" || strNumber == "nanf")
        return (SPECIAL);
    if (strNumber == "-inf" || strNumber == "+inf" || strNumber == "nan")
        return (SPECIAL);

    // ASCII_PRINTABLE
    bool isInt = strNumber.find_first_not_of("0123456789") == std::string::npos;
    if (strNumber.length() == 1 && !isInt)
        return (ASCII_PRINTABLE);

    // INT
    if (isInt)
        return (INT);

    // FLOAT con punto
    size_t pointCount = std::count(strNumber.begin(), strNumber.end(), '.');
    if (pointCount == 1 && !strNumber.empty() && strNumber[strNumber.size()-1] == 'f') {
        // Caso especial: ".f" → inválido
        if (strNumber == ".f")
            return (ERROR);

        return (FLOAT);
    }

    // DOUBLE
    if (pointCount == 1)
        return (DOUBLE);

    // FLOAT sin punto (ej: "123f")
    if (!strNumber.empty() && strNumber[strNumber.size()-1] == 'f') {
        std::string digitsOnly = strNumber.substr(0, strNumber.size()-1);
        if (!digitsOnly.empty() &&
            digitsOnly.find_first_not_of("0123456789") == std::string::npos)
            return (FLOAT);
    }

    return (ERROR);
}




