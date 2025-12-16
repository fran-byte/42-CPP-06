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

void charConvert(std::string strNumber)
{
    (void) strNumber;
}

int getType(std::string strNumber)
{
    // DETECTAMOS ESPECIALES
    if (strNumber == "-inff" || strNumber == "+inff" || strNumber == "nanf")
        return (SPECIAL);
    if (strNumber == "-inf" || strNumber == "+inf" || strNumber == "nan")
        return (SPECIAL);
    // DETECTAMOS SI ES ASCII_PRINTABLE
    bool isInt = strNumber.find_first_not_of("0123456789") == std::string::npos;
    bool isPoint = (strNumber.find_first_not_of("0123456789") == std::string::npos) && (strNumber.find_first_not_of(".") == std::string::npos);
    if (strNumber.length() == 1 && !isInt)
        return (ASCII_PRINTABLE);
    // DETECTAMOS INT
    if (isInt)
        return (INT);
    // Detectamos DOUBLE
    size_t pointCount = std::count(strNumber.begin(), strNumber.end(), '.');
    if (pointCount == 1)
        return (DOUBLE);

    return (ERROR);
}
