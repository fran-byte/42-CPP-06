/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 13:56:57 by frromero          #+#    #+#             */
/*   Updated: 2025/12/12 14:55:23 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <strings>
#include <iostream>

class ScalarConverter
{
public:
    ScalarConverter();
    ScalarConverter(std::string const strNumber);
    ~ScalarConverter();

    void static convert();

    ScalarConverter &operator=(ScalarConverter const &other);
};

std::ostream &operator<<(std::ostream &out, ScalarConverter const &other);

#endif