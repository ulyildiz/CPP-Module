#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

int main()
{
    std::ostringstream oss;
    long double f = std::strtold("8.988466e+307", NULL);
    long double d = std::strtod("8.988466e+307", NULL);
    std::string str = "2.247116e+301";

    std::cout.precision(15);
    if (f == d)
        std::cout << "Equal" << std::endl;
    else
        std::cout << "Not equal" << std::endl;
    std::cout << d << " " << f << std::endl; 

    std::cout << sizeof(d) << " " << sizeof(f) << std::endl;

    oss << f;
    std::cout << oss.str() << std::endl;
    std::cout << f << std::endl;
    std::cout << str << std::endl;
    if (str != oss.str())
        std::cout << "Not equal" << std::endl;
    else
        std::cout << "Equal" << std::endl;

	std::cout << (float)1.0e+40 << std::endl;
}
