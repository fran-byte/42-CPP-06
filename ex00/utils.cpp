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

void charConvert(std::string strNumber)
{
    (void) strNumber;
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

    //  INT
    if (isInt)
        return (INT);

    // FLOAT
    size_t pointCount = std::count(strNumber.begin(), strNumber.end(), '.');
    if (pointCount == 1 && !strNumber.empty() && strNumber[strNumber.size()-1] == 'f')
        return (FLOAT);

    //  DOUBLE
    if (pointCount == 1)
        return (DOUBLE);

    // FLOAT literal sin punto pero con sufijo f (ej. "5f")
    if (!strNumber.empty() && strNumber[strNumber.size()-1] == 'f') {
        std::string digitsOnly = strNumber.substr(0, strNumber.size()-1);
        if (!digitsOnly.empty() &&
            digitsOnly.find_first_not_of("0123456789") == std::string::npos)
            return (FLOAT);
    }

    return (ERROR);
}



