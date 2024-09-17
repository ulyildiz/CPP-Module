#include "Zombie.hpp"

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

int main(void)
{
	Zombie a("Xavi");

	{
		std::cout << "First line in first scope." << std::endl;
		Zombie	b("Kelvin");
	}
	std::cout << "First scope done." << std::endl;
	
	{
		Zombie	c = *newZombie("Obi-wan");
	}

	return (0);
}
