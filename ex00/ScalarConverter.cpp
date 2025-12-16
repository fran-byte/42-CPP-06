/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:52:18 by frromero          #+#    #+#             */
/*   Updated: 2025/12/16 21:19:38 by frromero         ###   ########.fr       */
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
    if (type == SPECIAL)
        specialConvert(strNumber);
    else if (type != ERROR)
        generalConvert(strNumber, type);
    else
        std::cout << "Unknown type: " << strNumber << std::endl;
}