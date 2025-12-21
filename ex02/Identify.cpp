/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 12:49:59 by frromero          #+#    #+#             */
/*   Updated: 2025/12/21 15:03:25 by frromero         ###   ########.fr       */
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
        std::cout << "A";
    else if (dynamic_cast<B *>(p))
        std::cout << "B";
    else if (dynamic_cast<C *>(p))
        std::cout << "C";
}

void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "A";
        return;
    }
    catch (...)
    {
        // It is not A
    }
    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "B";
        return;
    }
    catch (...)
    {
        // It is not B
    }
    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "C";
        return;
    }
    catch (...)
    {
        // It is not C
    }
}