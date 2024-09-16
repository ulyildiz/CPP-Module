#include <iostream>
#include <iomanip>
#include <sstream>
int main()
{
	std::string a = "merhaba arkadaşlar nasılsın?";

	std::cout << "|" << std::left << std::setw(10) << a.substr(0, 5) << "|";
}