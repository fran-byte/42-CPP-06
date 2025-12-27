/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 12:49:59 by frromero          #+#    #+#             */
/*   Updated: 2025/12/27 18:06:32 by frromero         ###   ########.fr       */
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

void identify(Base *p) // by pointer
{
    if (dynamic_cast<A *>(p)) /* Tries to casts pointer to an A pointer */
        std::cout << "A";
    else if (dynamic_cast<B *>(p))
        std::cout << "B";
    else if (dynamic_cast<C *>(p))
        std::cout << "C";
}

void identify(Base &p) // by reference
{
    try /* Tries to cast reference to an A reference */
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "A";
        return;
    }
    catch (...)
    { /* This is not a reference to A */
    }

    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "B";
        return;
    }
    catch (...)
    { /* This is not a reference to B */
    }

    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "C";
        return;
    }
    catch (...)
    { /* This is not a reference to C */
    }
}