#include <iostream>
#include <cmath>

int main()
{
    float f = 2.f;
    bool i = std::fmod(f, 1.0f);
    std::cout << (bool)i << std::endl;
    if (std::fmod(f, 1.0f) != 0.0f)
        std::cout << "fmod(2.5f, 1.0f) != 0.0f - " << i << std::endl;
    else
        std::cout << "fmod(2.5f, 1.0f) == 0.0f - " << i << std::endl;
}