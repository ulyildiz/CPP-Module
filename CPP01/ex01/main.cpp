#include <iostream>
#include <iomanip>
#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name);

int main(void)
{
	Zombie	*aHorde;
	int		hordeLen = 10;

	aHorde = zombieHorde(hordeLen, "Kelvins");

	for (int i = 0; i < hordeLen; i++)
	{
		std::cout << std::left << std::setw(5) << i;
		aHorde[i].announce();
	}
	delete[] aHorde;
	return (0);
}
