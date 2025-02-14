#include <iostream>
#include <sstream>

int main()
{
	std::stringstream ss;
	std::cout << (float &)ss << std::endl;
	std::cout << static_cast<float &>(ss) << std::endl;
}