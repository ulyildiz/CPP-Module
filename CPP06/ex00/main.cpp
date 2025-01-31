#include "ScalerConverter.hpp"

int main(int argc, char *argv[])
{
    (void)argc;
    std::string str(argv[1]);

    ScalerConverter::convert(str);
}