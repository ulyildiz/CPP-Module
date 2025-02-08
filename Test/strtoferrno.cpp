#include <iostream>
#include <errno.h>
#include <cstring>
#include <cmath>
int main()
{
	std::string input = "3.502823467e+38";

	float f = std::strtof(input.c_str(), NULL);
	float a = HUGE_VALF;
	if (errno == ERANGE)
		std::cout << "Error: " << strerror(errno) << std::endl;
	else
		std::cout << f << std::endl;
}