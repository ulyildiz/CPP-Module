#include "Dog.hpp"

Dog::Dog(void): Animal(), _brain(new Brain())
{
	std::cout << "Dog constructor." << std::endl;
	this->_type = "Dog";
}

Dog::Dog(const Dog& coppied): Animal(coppied), _brain(new Brain())
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

Brain*	Dog::getBrain(void) const
{
	return (this->_brain);
}

Dog&	Dog::operator=(const Dog& other)
{
	std::cout << "Dog assignment operator." << std::endl;
	if (this != &other)
	{
		if (this->_brain != NULL)
			delete this->_brain;
		this->_brain = new Brain(*(other.getBrain()));
		this->_type = other.getType();
	}
	return (*this);
}
