#include "Dog.hpp"

Dog::Dog(void): Animal()
{
	std::cout << "Dog constructor." << std::endl;
	this->_type = "Dog";
}

Dog::Dog(const Dog& coppied): Animal(coppied)
{
	std::cout << "Dog copy constructor." << std::endl;
	*this = coppied;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor." << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof Woof Woof Woof" << std::endl;
}

Dog&	Dog::operator=(const Dog& other)
{
	std::cout << "Dog operator assignment." << std::endl;
	if (this != &other)
		this->_type = other.getType();
	return (*this);
}
