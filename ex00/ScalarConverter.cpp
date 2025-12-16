/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:52:18 by frromero          #+#    #+#             */
/*   Updated: 2025/12/16 17:12:53 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &copy)
{
    *this = copy;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
    (void)other;
    return *this;
}

void ScalarConverter::convert(std::string const &strNumber)
{
    int type = getType(strNumber);

    switch (type)
    {
    case SPECIAL:
        specialConvert(strNumber);
        break;

    case ASCII_PRINTABLE:
        generalConvert(strNumber, type);
        break;

    case INT:
        generalConvert(strNumber, type);
        break;

    case FLOAT:
        std::cout << "Type: FLOAT" << std::endl;
        // floatConvert(strNumber);
        break;

    case DOUBLE:
        std::cout << "Type: DOUBLE" << std::endl;
        // doubleConvert(strNumber);
        break;

    case ERROR:
        std::cout << "Type: ERROR" << std::endl;
        // Error
        break;

    default:
        std::cout << "Type: UNKNOWN" << std::endl;
    }
}