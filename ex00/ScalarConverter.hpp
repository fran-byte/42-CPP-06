/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 13:56:57 by frromero          #+#    #+#             */
/*   Updated: 2025/12/16 17:00:33 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

int getType(std::string strNumber);

void generalConvert(std::string strNumber, int type);
void specialConvert(std::string strNumber);

enum e_type
{
    SPECIAL = 0,
    ASCII_PRINTABLE = 1,
    INT = 2,
    FLOAT = 3,
    DOUBLE = 4,
    ERROR = -1,
};

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(ScalarConverter const &copy);
    ~ScalarConverter();
    ScalarConverter &operator=(ScalarConverter const &other);

public:
    static void convert(std::string const &strNumber);
};

#endif