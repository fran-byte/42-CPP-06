/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:00:24 by frromero          #+#    #+#             */
/*   Updated: 2025/12/16 17:00:12 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cctype>
#include "ScalarConverter.hpp"
#include <algorithm>
#include <iomanip>

int isPrintable(int p)
{
    if (p < 32 || p > 126)
        return (0);
    return (1);
}

void generalConvert(std::string strNumber, int type)
{
    char c;
    int intNumber;
    std::cout << std::fixed << std::setprecision(1);

    if (type == ASCII_PRINTABLE)
    {

        c = strNumber[0];
        intNumber = static_cast<int>(c);
        float floatNumber = static_cast<float>(c);
        double doubleNumber = static_cast<double>(c);

        std::cout << "char:  '" << strNumber << "'" << std::endl;
        std::cout << "int:    " << intNumber << std::endl;
        std::cout << "float:  " << floatNumber << "f" << std::endl;
        std::cout << "double: " << doubleNumber << std::endl;
    }
    if (type == INT)
    {
        intNumber = atoi(strNumber.c_str());
        if (!isPrintable(intNumber))
            std::cout << "char:  Non displayable" << std::endl;
        else
            std::cout << "char:  '" << (static_cast<char>(intNumber)) << std::endl;
        // int intNumber = static_cast<int>(c);
        // float floatNumber = static_cast<float>(c);
        // double doubleNumber = static_cast<double>(c);
    }
}

void specialConvert(std::string strNumber)
{
    std::cout << "char:   impossible" << std::endl;
    std::cout << "int:    impossible" << std::endl;
    if (strNumber == "nan" || strNumber == "nanf")
    {
        std::cout << "float:  nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    if (strNumber == "-inff" || strNumber == "-inf")
    {
        std::cout << "float:  -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
    if (strNumber == "+inff" || strNumber == "+inf")
    {
        std::cout << "float:  +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
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
    if (pointCount == 1 && !strNumber.empty() && strNumber[strNumber.size() - 1] == 'f')
    {
        // Caso especial: ".f" → inválido
        if (strNumber == ".f")
            return (ERROR);

        return (FLOAT);
    }

    // DOUBLE
    if (pointCount == 1)
        return (DOUBLE);

    // FLOAT sin punto (ej: "123f")
    if (!strNumber.empty() && strNumber[strNumber.size() - 1] == 'f')
    {
        std::string digitsOnly = strNumber.substr(0, strNumber.size() - 1);
        if (!digitsOnly.empty() &&
            digitsOnly.find_first_not_of("0123456789") == std::string::npos)
            return (FLOAT);
    }

    return (ERROR);
}
