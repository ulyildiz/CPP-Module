#include <iostream>

int main()
{
	std::string a = "asd";
	std::string b = "dsa";

	std::cout << &a << std::endl;
	std::cout << &b << std::endl;

	a = b;
	std::cout << &a << std::endl;
}