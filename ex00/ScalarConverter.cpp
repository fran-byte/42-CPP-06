/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:52:18 by frromero          #+#    #+#             */
/*   Updated: 2025/12/12 15:43:38 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(std::string const strNumber)
{
    if(strNumber.empty())
                std::cout << "Invalid parameters [eg: ./conver -42.42 ]" << std::endl;

}

ScalarConverter::~ScalarConverter(){}