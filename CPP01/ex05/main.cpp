#include "Harl.hpp"

int main(void)
{
	std::string	input;
	Harl		harl;

	do {
		std::cout << "Enter level: ";
		std::getline(std::cin, input);
		harl.complain(input);
		std::cout << std::endl;
	} while(!std::cin.bad() && !std::cin.eof());

	return (0);
}