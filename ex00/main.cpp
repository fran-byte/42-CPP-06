/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:29:16 by frromero          #+#    #+#             */
/*   Updated: 2025/12/20 21:25:45 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc == 2 && argv[1][0] != '\0')
    {

        ScalarConverter::convert(argv[1]);
    }
    else
    {
        std::cout << "\nInvalid parameters.\n\n"
                  << "Usage:\n"
                  << "  ./convert <literal>\n\n"
                  << "Examples:\n"
                  << "  CHAR    ./convert \"'a'\"\n"
                  << "  CHAR    ./convert \"'1'\"\n"
                  << "  INT     ./convert 42\n"
                  << "  INT     ./convert \"42\"\n"
                  << "  FLOAT   ./convert 3.14f\n"
                  << "  FLOAT   ./convert \"3.14f\"\n"
                  << "  DOUBLE  ./convert 3.14\n"
                  << "  DOUBLE  ./convert \"3.14\"\n"
                  << "  SPECIAL ./convert nan\n"
                  << std::endl;
    }

    return (0);
}