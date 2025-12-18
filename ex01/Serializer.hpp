
#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>

struct Data
{
    int school;
    bool commonCore;
};

class Serializer
{
private:
    Serializer();
    Serializer(Serializer const &copy);
    ~Serializer();
    Serializer &operator=(Serializer const &other);

public:
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);
};

#endif
