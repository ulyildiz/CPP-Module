#include "Serializer.hpp"

Serializer::Serializer(): data("default", 20, 20.0f) {;}

Serializer::Serializer(const Serializer& coppied) : data(coppied.data)
{
    *this = coppied;
}

Serializer::~Serializer() {}

Serializer& Serializer::operator=(const Serializer& other) {
    (void)other;
    return *this;
}
