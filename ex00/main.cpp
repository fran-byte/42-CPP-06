/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:29:16 by frromero          #+#    #+#             */
/*   Updated: 2025/12/12 16:27:12 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc == 2 && argv[1][0] != '\0')   
        ScalarConverter argv[1];    
    else
        std::cout << "Invalid parameters [eg: ./conver -42.42 ]" << std::endl;
    return (0);
}