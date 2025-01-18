#include "Zombie.hpp"

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

int main(void)
{
	Zombie a("Xavi");
	Zombie *b;
	{
		std::cout << "First line in first scope." << std::endl;
		Zombie	c("Kelvin");
	}
	std::cout << "First scope done." << std::endl;
	
	b = newZombie("Ahsoka");
	{
		std::cout << "First line in second scope." << std::endl;
		Zombie*	d = newZombie("Obi-wan");
		delete d;
	}
	std::cout << "Second scope done." << std::endl;
	delete b;

	randomChump("Anakin");
	std::cout << "Random chump done." << std::endl;
	return (0);
}
