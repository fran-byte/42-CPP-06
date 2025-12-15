/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:00:24 by frromero          #+#    #+#             */
/*   Updated: 2025/12/15 22:10:30 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cctype>
#include "ScalarConverter.hpp"

int getType(std::string strNumber)
{
    if (strNumber == "-inff" || strNumber == "+inff" || strNumber == "nanf")
        return (FLOAT);
    if (strNumber == "-inf" || strNumber == "+inf" || strNumber == "nan")
        return (DOUBLE);
    // DETECTAMOS SI ES ASCII_PRINTABLE
    bool isInt = strNumber.find_first_not_of("0123456789") == std::string::npos;
    if (strNumber.length() == 1 && !isInt)
        return (ASCII_PRINTABLE);

    return (ERROR);
}
