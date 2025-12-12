/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 13:56:57 by frromero          #+#    #+#             */
/*   Updated: 2025/12/12 17:54:27 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(std::string const strNumber);
    ~ScalarConverter();
    ScalarConverter &operator=(ScalarConverter const &other);

public:
       static void convert(std::string const strNumber);
};

#endif