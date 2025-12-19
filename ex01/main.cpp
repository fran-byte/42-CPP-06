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

    Data* rawPtr = Serializer::deserialize(ptrData);

    std::cout << "After DESERIALIZE rawPtr: school = " << rawPtr->school << std::endl;
    std::cout << "After DESERIALIZE rawPtr: commonCore = " << rawPtr->commonCore << std::endl;

    std::cout << "Address original ptr: " << ptr << std::endl;
    std::cout << "Address deserialized Other-ptr: " << rawPtr << std::endl;

    return 0;
}
