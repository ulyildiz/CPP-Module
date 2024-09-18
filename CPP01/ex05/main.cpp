#include "Harl.hpp"

int main(void)
{
	std::string	input;
	Harl		harl;

	while (std::getline(std::cin, input))
	{
		harl.complain(input);
	}
	return (0);
}