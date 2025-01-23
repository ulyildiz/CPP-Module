#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	int maxAnimal = 10;
	Animal* animal[maxAnimal];

	for (int i = 0; i < maxAnimal; i++)
	{
		if (i % 2)
			animal[i] = new Cat();
		else
			animal[i] = new Dog();
	}

	for (int i = 0; i < maxAnimal; i++)
		animal[i]->makeSound();	

	for (int i = 0; i < maxAnimal; i++)
		delete animal[i];

	Cat a;

	for (int i = 1; i < 101; i++)
		(*a.getBrain()).setIdea("Cat_a Ideas", i);
	for (int i = 1; i < 101; i++)
		std::cout << (*a.getBrain()).getIdea(i) << " " << i << std::endl;

	{
		Cat c = a;
	}
	
	return (0);
}