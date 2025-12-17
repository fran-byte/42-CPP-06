/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:29:16 by frromero          #+#    #+#             */
/*   Updated: 2025/12/17 20:21:58 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc == 2 && argv[1][0] != '\0')
    {
        bool printable = true;
        for (int i = 0; argv[1][i]; i++)
        {
            if (argv[1][i] < 32 || argv[1][i] > 126)
            {
                printable = false;
                break;
            }
        }
        if (printable)
            ScalarConverter::convert(argv[1]);
        else
            std::cout << "Parameter Not Printable" << std::endl;
    }
    else
    {
        std::cout << "Invalid parameters [eg: ./convert -42.42 ]" << std::endl;
        std::cout << "Usage: ./convert <literal>" << std::endl;
        std::cout << "Literal must be a single C++ literal: char, int, float, or double." << std::endl;
        std::cout << "Examples:" << std::endl;
        std::cout << "  ./convert a" << std::endl;
        std::cout << "  ./convert 42" << std::endl;
        std::cout << "  ./convert 3.14f" << std::endl;
        std::cout << "  ./convert nan" << std::endl;
    }
    return (0);
}