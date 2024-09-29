#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	int maxAnimal = 10;
	//AAnimal a;
	AAnimal* animal[maxAnimal];

	for (int i = 0; i < maxAnimal; i++)
	{
		if (i % 2)
			animal[i] = new Cat();
		else
			animal[i] = new Dog();
	}

	for (int i = 0; i < maxAnimal; i++)
		animal[i]->makeSound();
	
	/*
		use idea variable for example
	*/

	for (int i = 0; i < maxAnimal; i++)
		delete animal[i];
	return (0);	
}