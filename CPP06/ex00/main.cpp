#include "ScalerConverter.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./convert [value]" << std::endl;
        return (1);
    }
    std::string str(argv[1]);

    ScalerConverter::convert(str);
    return (0);
}