/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 13:18:31 by frromero          #+#    #+#             */
/*   Updated: 2025/12/21 14:33:45 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include "Identify.hpp"

int main()
{
    std::srand(std::time(NULL));

    Base *obj1 = generate();
    std::cout << "The actual type of the object pointed:" << std::endl;
    identify(obj1);
    std::cout << "The actual type of the object referenced:" << std::endl;
    identify(*obj1);
    delete (obj1);

    return 0;
}