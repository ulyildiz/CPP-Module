#include "Serializer.hpp"

int main(void)
{
    Data data("Hello", 42, 42.42f);
    uintptr_t serialized = Serializer::serialize(&data);
    Data* deserialized = Serializer::deserialize(serialized);

    std::cout << "Deserialized data:" << deserialized << std::endl;
    std::cout << "str: " << deserialized->str << std::endl;
    std::cout << "i: " << deserialized->i << std::endl;
    std::cout << "f: " << deserialized->f << std::endl;

    std::cout << "Serialized data: " << serialized << std::endl;

    std::cout << "Original data:" << &data << std::endl;
    std::cout << "str: " << data.str << std::endl;
    std::cout << "i: " << data.i << std::endl;
    std::cout << "f: " << data.f << std::endl;

	/* {
		unsigned long* nonReinterpretCast = &data;

		std::cout << "nonReinterpretCast: " << nonReinterpretCast << std::endl;

		Data*	nonReinterpretCastData = (Data*)nonReinterpretCast;

		std::cout << "nonReinterpretCastData: " << nonReinterpretCastData << std::endl;
		std::cout << "str: " << nonReinterpretCastData->str << std::endl;
		std::cout << "i: " << nonReinterpretCastData->i << std::endl;
		std::cout << "f: " << nonReinterpretCastData->f << std::endl;
	} */

    return 0;
}