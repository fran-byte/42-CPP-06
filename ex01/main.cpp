#include "Serializer.hpp"
#include <cstddef>
#include <iostream>
#include <iomanip>

int main(void)
{
    Data data;
    Data *ptr = &data;

    ptr->commonCore = true;
    ptr->school = 42;

    uintptr_t ptrData = Serializer::serialize(ptr);
    std::cout << "Unsigned int ptr: " << ptrData;
    std::cout << " to Hexadecimal: 0x" << std::hex << ptrData << std::endl;
    Data rawPtr = *Serializer::deserialize(ptrData);
    std::cout << "adress ptr: " << &rawPtr << std::endl;

    return 0;
}