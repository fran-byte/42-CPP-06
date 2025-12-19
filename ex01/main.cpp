#include "Serializer.hpp"
#include <iostream>
#include <iomanip>

int main(void)
{
    Data data;
    Data *ptr = &data;

    ptr->commonCore = true;
    ptr->school = 42;

    std::cout << "ORIGINAL DATA ptr: school = " << ptr->school << std::endl;
    std::cout << "ORIGINAL DATA ptr: commonCore = " << ptr->commonCore << std::endl;

    uintptr_t ptrData = Serializer::serialize(ptr);

    std::cout << "Serialized pointer (uintptr_t): " << ptrData << std::endl;
    std::cout << "Hexadecimal: 0x" << std::hex << ptrData << std::dec << std::endl;

    std::cout << "********************************************************************" << std::endl;

    Data* otherPtr = Serializer::deserialize(ptrData);

    std::cout << "After DESERIALIZE otherPtr: school = " << otherPtr->school << std::endl;
    std::cout << "After DESERIALIZE otherPtr: commonCore = " << otherPtr->commonCore << std::endl;

    std::cout << "Address original ptr: " << ptr << std::endl;
    std::cout << "Address deserialized otherPtr: " << otherPtr << std::endl;

    return 0;
}
