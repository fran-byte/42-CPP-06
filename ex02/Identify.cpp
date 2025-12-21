/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 12:49:59 by frromero          #+#    #+#             */
/*   Updated: 2025/12/21 14:29:37 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

/*Pointer to random class (A B C)*/
Base *generate(void)
{
    int randomNum = rand() % 3;
    if (randomNum == 0)
        return new A();
    else if (randomNum == 1)
        return new B();
    return new C();
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base &p)
{
    try
    {
        A &refA = dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        (void)refA;
    }
    catch (...)
    {
        // It is not A
    }
    try
    {
        B &refB = dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        (void)refB;
    }
    catch (...)
    {
        // It is not B
    }
    try
    {
        C &refC = dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        (void)refC;
    }
    catch (...)
    {
        // It is not C
    }
}