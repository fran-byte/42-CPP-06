/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:52:18 by frromero          #+#    #+#             */
/*   Updated: 2025/12/13 19:47:57 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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

void ScalarConverter::convert(std::string const strNumber)
{
    std::cout << strNumber;
}