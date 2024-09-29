#include "Cat.hpp"

Cat::Cat(void): Animal()
{
	std::cout << "Cat constructor." << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat& coppied): Animal(coppied)
{
	std::cout << "Cat copy constructor." << std::endl;
	*this = coppied;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor." << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow Meow Meow Meow" << std::endl;
}

Cat&	Cat::operator=(const Cat& other)
{
	this->type = other.getType();
	return (*this);
}