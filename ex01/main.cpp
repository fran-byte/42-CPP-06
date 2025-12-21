#include "Serializer.hpp"
#include <iostream>
#include <iomanip>
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"

int main(void)
{
    Data data;
    Data *ptr = &data;

    ptr->commonCore = true;
    ptr->school = 42;

    std::cout << std::endl;
    std::cout << BOLD << CYAN;
    std::cout << "                    POINTER CASTING                    " << std::endl;
    std::cout << RESET;
    std::cout << std::endl;

    std::cout << BOLD << CYAN;
    std::cout << " *******************************************************" << std::endl;
    std::cout << " ORIGINAL DATA" << std::endl;
    std::cout << " *******************************************************" << std::endl;
    std::cout << RESET;

    std::cout << GREEN << " ptr → school      = " << ptr->school << RESET << std::endl;
    std::cout << GREEN << " ptr → commonCore  = " << ptr->commonCore << RESET << std::endl;

    uintptr_t ptrData = Serializer::serialize(ptr);

    std::cout << YELLOW;
    std::cout << " Original Data pointer (hex) : 0x"
              << std::hex << ptrData << std::dec << std::endl;
    std::cout << RESET;

    std::cout << std::endl;

    std::cout << BOLD << CYAN;
    std::cout << " *******************************************************" << std::endl;
    std::cout << " SERIALIZATION" << std::endl;
    std::cout << " *******************************************************" << std::endl;
    std::cout << RESET;

    std::cout << YELLOW
              << " Serialized uintptr_t value : " << ptrData
              << RESET << std::endl;

    Data *otherPtr = Serializer::deserialize(ptrData);

    std::cout << std::endl;

    std::cout << BOLD << CYAN;
    std::cout << " *******************************************************" << std::endl;
    std::cout << " DESERIALIZATION" << std::endl;
    std::cout << " *******************************************************" << std::endl;
    std::cout << RESET;

    std::cout << YELLOW
              << " Deserialized pointer       : " << otherPtr
              << RESET << std::endl;

    std::cout << GREEN;
    std::cout << " otherPtr → school          = " << otherPtr->school << std::endl;
    std::cout << " otherPtr → commonCore      = " << otherPtr->commonCore << std::endl;
    std::cout << RESET;

    std::cout << std::endl;

    std::cout << BOLD << CYAN;
    std::cout << " *******************************************************" << std::endl;
    std::cout << RESET;
    std::cout << std::endl;

    return 0;
}
