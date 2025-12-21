/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 11:27:54 by frromero          #+#    #+#             */
/*   Updated: 2025/12/21 11:27:54 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>
#include <cerrno>

/* Class constructors ******************************************************** */
Serializer::Serializer() {}
Serializer::Serializer(Serializer const &copy) { (void)copy; }
Serializer::~Serializer() {}
Serializer &Serializer::operator=(Serializer const &other)
{
    (void)other;
    return *this;
}

/* Static Methods  *********************************************************** */

uintptr_t Serializer::serialize(Data *ptr)
{
    if (!ptr)
    {
        std::cout << "!ptr";
        errno = EINVAL;
        return 0;
    }
    uintptr_t ptrInt = reinterpret_cast<uintptr_t>(ptr);

    errno = 0;
    return ptrInt;
}

Data *Serializer::deserialize(uintptr_t raw)
{
    if (!raw)
    {
        errno = EINVAL;
        return 0;
    }
    Data *ptr = reinterpret_cast<Data *>(raw);
    errno = 0;
    return ptr;
}