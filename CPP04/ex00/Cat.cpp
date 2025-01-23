#include "Cat.hpp"

Cat::Cat(void): Animal()
{
	std::cout << "Cat constructor." << std::endl;
	this->_type = "Cat";
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
	std::cout << "Cat operator assignment." << std::endl;
	if (this != &other)
		this->_type = other.getType();
	return (*this);
}
