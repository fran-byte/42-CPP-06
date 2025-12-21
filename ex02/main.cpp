/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 13:18:31 by frromero          #+#    #+#             */
/*   Updated: 2025/12/21 15:33:51 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include "Identify.hpp"
#include <cstdlib>
#include <ctime>
#include "Identify.hpp"

int main()
{
    srand(time(NULL));

    Base *obj1 = generate();
    Base *obj2 = generate();
    Base *obj3 = generate();
    Base *obj4 = generate();

    std::cout << std::endl;
    std::cout << "\033[33m" << "                  - TYPE -" << std::endl;
    std::cout << "\033[0m" << "Object pointed:    ";
    identify(obj1);
    std::cout << " ";
    identify(obj2);
    std::cout << " ";
    identify(obj3);
    std::cout << " ";
    identify(obj4);
    std::cout << std::endl;

    std::cout << "Object referenced: ";
    identify(*obj1);
    std::cout << " ";
    identify(*obj2);
    std::cout << " ";
    identify(*obj3);
    std::cout << " ";
    identify(*obj4);
    std::cout << std::endl;
    std::cout << std::endl;

    delete obj1;
    delete obj2;
    delete obj3;
    delete obj4;

    return 0;
}