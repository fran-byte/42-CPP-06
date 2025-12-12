/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 13:56:57 by frromero          #+#    #+#             */
/*   Updated: 2025/12/12 14:28:58 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings>

class ScalarConverter
{
public:
    ScalarConverter();
    ScalarConverter(std::string const strNumber);
    ScalarConverter(int intNumber);
    ScalarConverter(float floatNumber);
    ScalarConverter(double doubleNumber);
    ScalarConverter(ScalarConverter const &copy);
    ~ScalarConverter();

    void static convert();

    ScalarConverter &operator=(ScalarConverter const &other);
};

std::ostream &operator<<(std::ostream &out, ScalarConverter const &other);