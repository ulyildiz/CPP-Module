#include <iostream>
#include <cstdlib>   // for std::strtof
#include <cmath>     // for std::isnan, std::isinf

int main() {
    std::string input = "inff";
    std::string input2 = "nan";
    float f = std::strtof(input.c_str(), NULL);
    double d = std::strtod(input2.c_str(), NULL);
    if (std::isnan(f))
        std::cout << "Converted to NaN" << std::endl;
    else if (std::isinf(f))
        std::cout << "Converted to Infinity" << std::endl;
    else
        std::cout << "Converted value: " << f << std::endl;

    if (f == d)
        std::cout << "asd" << std::endl;
    std::cout << static_cast<float>(d) << std::endl;
    return 0;
}
