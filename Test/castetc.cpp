#include <iostream>
#include <cmath>
#include <limits>
#include <cstdlib>

int main() {
    int x = std::isnan(333);  // ERROR: cannot convert NaN to int
    double y = std::numeric_limits<double>::infinity();  // ERROR
    std::cout << x << " " << y << std::endl;
    if (std::numeric_limits<double>::infinity() == std::numeric_limits<float>::has_quiet_NaN())
        std::cout << "equal" << std::endl;
    return 0;
}
