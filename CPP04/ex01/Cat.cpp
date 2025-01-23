#include "Cat.hpp"

Cat::Cat(void): Animal(), _brain(new Brain())
{
	std::cout << "Cat constructor." << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat& coppied): Animal(coppied), _brain(new Brain())
{
	std::cout << "Cat copy constructor." << std::endl;
	*this = coppied;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor." << std::endl;
	delete this->_brain;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow Meow Meow Meow" << std::endl;
}

Brain*	Cat::getBrain(void) const
{
	return (this->_brain);
}

Cat&	Cat::operator=(const Cat& other)
{
	std::cout << "Cat assignment operator." << std::endl;
	if (this != &other)
	{
		this->_type = other.getType();
		for(int i = 1; i < 101; i++)
			this->_brain->setIdea(other._brain->getIdea(i), i);
	}
	return (*this);
}