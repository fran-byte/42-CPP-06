/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 13:56:57 by frromero          #+#    #+#             */
/*   Updated: 2025/12/21 17:40:53 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

/* Enum for literal types */
enum e_type
{
    ERROR = -1,
    SPECIAL,
    CHAR,
    INT,
    FLOAT,
    DOUBLE
};

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(ScalarConverter const &copy);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();

public:
    static void convert(const std::string &s);
};

#endif