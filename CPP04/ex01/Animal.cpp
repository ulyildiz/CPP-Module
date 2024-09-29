#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal constructor." << std::endl;
	this->type = "Animal";
}

Animal::Animal(const Animal& coppied)
{
	std::cout << "Animal copy constructor." << std::endl;
	*this = coppied;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor." << std::endl;
}

const std::string&	Animal::getType(void) const
{
	return (this->type);
}

void	Animal::makeSound(void) const
{
	std::cout << "Some kind of animal noises." << std::endl;
}

Animal&	Animal::operator=(const Animal& other)
{
	this->type = other.getType();
	return (*this);
}

