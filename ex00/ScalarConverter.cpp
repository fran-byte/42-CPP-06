/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 13:57:03 by frromero          #+#    #+#             */
/*   Updated: 2025/12/17 21:11:16 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 13:57:03 by frromero          #+#    #+#             */
/*   Updated: 2025/12/17 21:01:15 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <cfloat>
#include <cmath>
#include <iomanip>
#include <string>
#include <cctype>

/* Detect input type */
static int getType(const std::string &str)
{
    /* Special cases */
    if (str == "-inff" || str == "+inff" || str == "nanf" ||
        str == "-inf" || str == "+inf" || str == "nan")
        return SPECIAL;

    /* Single character */
    if (str.length() == 1 && !isdigit(str[0]) && str[0] != '-' && str[0] != '+')
        return CHAR;

    /* Check for float suffix */
    bool hasF = (str.length() > 1 && str[str.length() - 1] == 'f');
    std::string num = hasF ? str.substr(0, str.length() - 1) : str;

    /* Validate format */
    size_t dots = 0;
    bool hasDigit = false;
    size_t i = (num[0] == '-' || num[0] == '+') ? 1 : 0;

    for (; i < num.length(); ++i)
    {
        if (isdigit(num[i]))
            hasDigit = true;
        else if (num[i] == '.')
        {
            if (++dots > 1)
                return ERROR;
        }
        else
            return ERROR;
    }

    if (!hasDigit)
        return ERROR;

    /* Determine type */
    if (hasF && dots <= 1)
        return FLOAT;
    if (!hasF && dots == 1)
        return DOUBLE;
    if (!hasF && dots == 0)
        return INT;

    return ERROR;
}

/* Display results */
static void displayResults(double d)
{
    /* Char */
    if (!std::isnan(d) && !std::isinf(d) && d >= 0 && d <= 127)
    {
        char c = static_cast<char>(d);
        std::cout << "char: " << (isprint(c) ? "'" + std::string(1, c) + "'" : "Non displayable") << std::endl;
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
    }

    /* Int */
    if (!std::isnan(d) && !std::isinf(d) && d >= INT_MIN && d <= INT_MAX)
    {
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    }
    else
    {
        std::cout << "int: impossible" << std::endl;
    }

    /* Float */
    float f = static_cast<float>(d);
    std::cout << "float: ";
    if (std::isnan(d))
        std::cout << "nanf";
    else if (std::isinf(d))
        std::cout << (d < 0 ? "-inff" : "+inff");
    else
    {
        std::cout << f;
        if (d == static_cast<long long>(d) && d <= 1e6 && d >= -1e6)
            std::cout << ".0";
        std::cout << "f";
    }
    std::cout << std::endl;

    /* Double */
    std::cout << "double: ";
    if (std::isnan(d))
        std::cout << "nan";
    else if (std::isinf(d))
        std::cout << (d < 0 ? "-inf" : "+inf");
    else
    {
        std::cout << d;
        if (d == static_cast<long long>(d) && d <= 1e6 && d >= -1e6)
            std::cout << ".0";
    }
    std::cout << std::endl;
}

/* Class methods */
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &) {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) { return *this; }

/* Main conversion */
void ScalarConverter::convert(const std::string &str)
{
    int type = getType(str);

    if (type == ERROR)
    {
        std::cout << "Invalid input" << std::endl;
        return;
    }

    if (type == SPECIAL)
    {
        std::cout << "char: impossible\nint: impossible\n";
        if (str == "nan" || str == "nanf")
            std::cout << "float: nanf\ndouble: nan\n";
        else if (str == "-inf" || str == "-inff")
            std::cout << "float: -inff\ndouble: -inf\n";
        else
            std::cout << "float: +inff\ndouble: +inf\n";
        return;
    }

    if (type == CHAR)
    {
        displayResults(static_cast<double>(str[0]));
        return;
    }

    /* Numeric types */
    std::string num = str;
    if (type == FLOAT)
        num = str.substr(0, str.length() - 1);

    char *end;
    errno = 0;
    double d = strtod(num.c_str(), &end);

    if (errno == ERANGE)
    {
        std::cout << "char: impossible\nint: impossible\n";
        if (d == HUGE_VAL)
            std::cout << "float: +inff\ndouble: +inf\n";
        else if (d == -HUGE_VAL)
            std::cout << "float: -inff\ndouble: -inf\n";
        else
            std::cout << "float: 0.0f\ndouble: 0.0\n";
    }
    else if (end == num.c_str())
    {
        std::cout << "Invalid input" << std::endl;
    }
    else
    {
        displayResults(d);
    }
}