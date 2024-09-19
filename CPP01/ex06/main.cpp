#include "Harl.hpp"

int main(int argc, char *argv[])
{
	Harl	harl;
	(void)argv;

	if (argc != 2)
	{
		std::cout << "Just enter level." << std::endl;
		return (1);
	}

	harl.complain(argv[1]);
	
	return (0);
}