/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 13:57:03 by frromero          #+#    #+#             */
/*   Updated: 2025/12/21 17:27:29 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <cfloat>
#include <cmath>
#include <string>
#include <cctype>

/* Detect type ************************************************************** */
static int getType(const std::string &str)
{
    if (str == "-inff" || str == "+inff" || str == "nanf" || str == "-inf" || str == "+inf" || str == "nan")
        return SPECIAL;
    if (str.length() == 3 && str[0] == 39 && str[2] == 39 && str[1] >= 32 && str[1] <= 126)
    {

        return CHAR;
    };

    bool isFloat = false;
    std::string num = str;
    if (str.length() > 1 && str[str.length() - 1] == 'f')
    {
        isFloat = true;
        num = str.substr(0, str.length() - 1);
    }

    size_t dots = 0;
    bool digit = false;
    size_t i = 0;
    if (!num.empty() && (num[0] == '-' || num[0] == '+'))
        i = 1;

    for (; i < num.length(); ++i)
    {
        if (std::isdigit(num[i]))
            digit = true;
        else if (num[i] == '.')
        {
            ++dots;
            if (dots > 1)
                return ERROR;
        }
        else
            return ERROR;
    }

    if (!digit)
        return ERROR;
    if (isFloat)
        return FLOAT;
    if (dots > 0)
        return DOUBLE;
    return INT;
}

/* Display results *********************************************************** */
static void displayResults(double d)
{
    // Char
    if (d >= 0 && d <= 127)
    {
        if (d >= 32 && d <= 126)
            std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    else
        std::cout << "char: impossible" << std::endl;

    // Int
    if (!std::isnan(d) && !std::isinf(d) && d >= INT_MIN && d <= INT_MAX)
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;

    // Float
    float f = static_cast<float>(d);
    std::cout << "float: ";
    if (std::isnan(d))
        std::cout << "nanf";
    else if (std::isinf(d))
    {
        if (d < 0)
            std::cout << "-inff";
        else
            std::cout << "+inff";
    }
    else
    {
        std::cout << f;
        if (d == static_cast<long long>(d) && d <= 1000000 && d >= -1000000)
            std::cout << ".0";
        std::cout << "f";
    }
    std::cout << std::endl;

    // Double
    std::cout << "double: ";
    if (std::isnan(d))
        std::cout << "nan";
    else if (std::isinf(d))
    {
        if (d < 0)
            std::cout << "-inf";
        else
            std::cout << "+inf";
    }
    else
    {
        std::cout << d;
        if (d == static_cast<long long>(d) && d <= 1000000 && d >= -1000000)
            std::cout << ".0";
    }
    std::cout << std::endl;
}

/* Class constructors ******************************************************** */
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const &o) { (void)o; }
ScalarConverter::~ScalarConverter() {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) { return *this; }

/* Main conversion *********************************************************** */
void ScalarConverter::convert(const std::string &s)
{
    int t = getType(s);
    if (t == ERROR)
    {
        std::cout << "Not valid input" << std::endl;
        return;
    }

    if (t == SPECIAL)
    {
        std::cout << "char: impossible\nint: impossible" << std::endl;
        if (s == "nan" || s == "nanf")
            std::cout << "float: nanf\ndouble: nan" << std::endl;
        else if (s == "-inf" || s == "-inff")
            std::cout << "float: -inff\ndouble: -inf" << std::endl;
        else
            std::cout << "float: +inff\ndouble: +inf" << std::endl;
        return;
    }

    if (t == CHAR)
    {
        displayResults(static_cast<double>(s[1]));
        return;
    }

    std::string num;
    if (t == FLOAT)
        num = s.substr(0, s.length() - 1);
    else
        num = s;

    char *end;
    errno = 0; /* error function */
    double val = std::strtod(num.c_str(), &end);

    if (errno == ERANGE) /* RangeError ? */
    {
        std::cout << "char: impossible\nint: impossible" << std::endl;
        if (val == HUGE_VAL)
            std::cout << "float: +inff\ndouble: +inf" << std::endl;
        else if (val == -HUGE_VAL)
            std::cout << "float: -inff\ndouble: -inf" << std::endl;
        else
            std::cout << "float: 0.0f\ndouble: 0.0" << std::endl;
    }
    else if (end == num.c_str())
        std::cout << "Not valid input" << std::endl;

    else
        displayResults(val);
}
