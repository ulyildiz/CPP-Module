#include "Cat.hpp"
#include "Dog.hpp"

#define animalCount 10

int main(void)
{
	AAnimal* stables[animalCount];

	for (int i = 0; i < animalCount; i++)
	{
		if (i < 5)
		{
			stables[i] = new Dog();
			continue ;
		}
		stables[i] = new Cat();
	}
	for (int i = 0; i < animalCount; i++)
		stables[i]->makeSound();

	for (int i = 0; i < animalCount; i++)
		delete stables[i];

	return (0);	
}
