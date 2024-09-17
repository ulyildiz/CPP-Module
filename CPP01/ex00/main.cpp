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
		Zombie*	d = newZombie("Obi-wan");
		delete d;
	}
	delete b;
	return (0);
}
