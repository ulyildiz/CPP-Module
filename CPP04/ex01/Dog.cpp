#include "Dog.hpp"

Dog::Dog(void): Animal(), _brain(new Brain())
{
	std::cout << "Dog constructor." << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog& coppied): Animal(coppied), _brain(NULL)
{
	std::cout << "Dog copy constructor." << std::endl;
	*this = coppied;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor." << std::endl;
	delete this->_brain;
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof Woof Woof Woof" << std::endl;
}

Dog&	Dog::operator=(const Dog& other)
{
	this->type = other.getType();
	for(int i = 0; i < 100; i++)
		this->_brain->setIdea(other._brain->getIdea(i), i);
	return (*this);
}