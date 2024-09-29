#include <iostream>

int main()
{
	std::string a = "asd";
	std::string b = "dsa";

	std::cout << &a << std::endl;
	std::cout << &b << std::endl;
	std::string c(a);
	a = b;
	std::cout << &a << std::endl;
	std::cout << &c << std::endl;
}