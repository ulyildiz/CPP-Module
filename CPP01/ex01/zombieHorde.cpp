#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	return (new Zombie[N](name));
}
