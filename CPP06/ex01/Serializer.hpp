#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

class   Serializer {
    private:
        Serializer();
        Serializer(const Serializer& coppied);
        ~Serializer();
        Serializer& operator=(const Serializer& other);

        struct Data {
            std::string str;
            int         i;
            float       f;

            Data(std::string str, int i, float f): str(str), i(i), f(f) {}
        } data;

    public:
        static uintptr_t    serialize(Data* ptr);
        static Data*        deserialize(uintptr_t raw);

};

#endif