#include "Fixed.hpp"
#include <bitset>

int main( void )
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << a << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	return 0;
}

//	std::cout << std::bitset<32>(b.getRawBits()).to_string() << std::endl;