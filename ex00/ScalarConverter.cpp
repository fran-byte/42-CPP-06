/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 13:57:03 by frromero          #+#    #+#             */
/*   Updated: 2025/12/17 20:38:28 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream> /* cout, endl */
#include <cstdlib>  /* strtod, strtol */
#include <cerrno>   /* errno, ERANGE */
#include <climits>  /* INT_MIN, INT_MAX */
#include <cfloat>   /* FLT_MAX, FLT_MIN */
#include <cmath>    /* isnan, isinf, floor */
#include <iomanip>  /* setprecision, fixed */
#include <string>   /* std::string */
#include <cctype>   /* isdigit, isprint */

/* **************** DETECT TYPE ******************************************** */
static int getType(const std::string &strLiteral)
{
    std::string str = strLiteral;

    /* Check special cases */
    if (str == "-inff" || str == "+inff" || str == "nanf" ||
        str == "-inf" || str == "+inf" || str == "nan")
        return TYPE_SPECIAL;

    /* Check for single character */
    if (str.length() == 1 && !std::isdigit(str[0]) &&
        str[0] != '-' && str[0] != '+')
        return TYPE_CHAR;

    /* Check for float (ends with 'f') */
    bool isFloat = false;
    if (str.length() > 1 && str[str.length() - 1] == 'f')
    {
        isFloat = true;
        str = str.substr(0, str.length() - 1);
    }

    /* Validate characters / count decimal points */
    size_t pointCount = 0;
    bool hasDigit = false;
    size_t start = 0;

    if (!str.empty() && (str[0] == '-' || str[0] == '+'))
        start = 1;

    for (size_t i = start; i < str.length(); ++i)
    {
        char c = str[i];

        if (std::isdigit(c))
            hasDigit = true;
        else if (c == '.')
        {
            pointCount++;
            if (pointCount > 1)
                return TYPE_ERROR;
        }
        else
            return TYPE_ERROR;
    }

    if (!hasDigit)
        return TYPE_ERROR;

    /* Determine final type */
    if (isFloat && pointCount <= 1)
        return TYPE_FLOAT;
    else if (!isFloat && pointCount == 1)
        return TYPE_DOUBLE;
    else if (!isFloat && pointCount == 0)
        return TYPE_INT;

    return TYPE_ERROR;
}

/* Display conversion results for all types */
static void displayResults(double d)
{
    /* Char conversion - truncate to integer */
    if (!std::isnan(d) && !std::isinf(d) &&
        d >= 0 && d <= 127)
    {
        /* Truncate to integer */
        int truncated = static_cast<int>(d);
        char c = static_cast<char>(truncated);
        if (std::isprint(c))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
    }

    /* Int conversion - truncate if within range */
    if (!std::isnan(d) && !std::isinf(d))
    {
        /* Check if value is within int range */
        if (d >= static_cast<double>(INT_MIN) &&
            d <= static_cast<double>(INT_MAX))
        {
            /* Truncate */
            long long truncated = static_cast<long long>(d);
            std::cout << "int: " << static_cast<int>(truncated) << std::endl;
        }
        else
        {
            std::cout << "int: impossible" << std::endl;
        }
    }
    else
    {
        std::cout << "int: impossible" << std::endl;
    }

    /* Float conversion */
    float f = static_cast<float>(d);
    std::cout << "float: ";

    if (std::isnan(d))
        std::cout << "nanf";
    else if (std::isinf(d))
        std::cout << (d < 0 ? "-inff" : "+inff");
    else
    {
        std::cout << f;
        /* Show .0 for values close to integers */
        if (d == static_cast<long long>(d) &&
            d <= 1000000 && d >= -1000000)
            std::cout << ".0";
        std::cout << "f";
    }
    std::cout << std::endl;

    /* Double conversion */
    std::cout << "double: ";
    if (std::isnan(d))
        std::cout << "nan";
    else if (std::isinf(d))
        std::cout << (d < 0 ? "-inf" : "+inf");
    else
    {
        std::cout << d;
        /* Show .0 for values close to integers */
        if (d == static_cast<long long>(d) &&
            d <= 1000000 && d >= -1000000)
            std::cout << ".0";
    }
    std::cout << std::endl;
}

/* **************  ScalarCoverter  *****************************/
ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}

/* ***************************************************************** */
/*              ScalarCoverter - Method                              */
/* ***************************************************************** */
void ScalarConverter::convert(const std::string &strLiteral)
{
    int type = getType(strLiteral);

    if (type == TYPE_ERROR)
    {
        std::cout << "Invalid input" << std::endl;
        return;
    }

    /* Handle special cases****************************************** */
    if (type == TYPE_SPECIAL)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;

        if (strLiteral == "nan" || strLiteral == "nanf")
        {
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        }
        else if (strLiteral == "-inf" || strLiteral == "-inff")
        {
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        }
        else
        {
            std::cout << "float: +inff" << std::endl;
            std::cout << "double: +inf" << std::endl;
        }
        return;
    }

    /* CONVERT ********************************************************/
    if (type == TYPE_CHAR)
    {
        char c = strLiteral[0];
        displayResults(static_cast<double>(c));
    }
    else
    {
        std::string convertStr = strLiteral;
        if (type == TYPE_FLOAT && !strLiteral.empty() &&
            strLiteral[strLiteral.length() - 1] == 'f')
            convertStr = strLiteral.substr(0, strLiteral.length() - 1);

        char *end;
        errno = 0;
        double d = std::strtod(convertStr.c_str(), &end);

        if (errno == ERANGE)
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;

            if (d == HUGE_VAL)
            {
                std::cout << "float: +inff" << std::endl;
                std::cout << "double: +inf" << std::endl;
            }
            else if (d == -HUGE_VAL)
            {
                std::cout << "float: -inff" << std::endl;
                std::cout << "double: -inf" << std::endl;
            }
            else
            {
                std::cout << "float: 0.0f" << std::endl;
                std::cout << "double: 0.0" << std::endl;
            }
        }
        else if (end == convertStr.c_str())
            std::cout << "Invalid input" << std::endl;
        else
            displayResults(d);
    }
}