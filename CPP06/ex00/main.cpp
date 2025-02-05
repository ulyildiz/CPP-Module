#include "ScalerConverter.hpp"

int main(int argc, char *argv[])
{
    (void)argc;
    std::string str(argv[1]);

    ScalerConverter::convert(str);
} //whne input is nan, convert display int too, it should not