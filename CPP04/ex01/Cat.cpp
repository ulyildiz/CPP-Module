#include "Cat.hpp"

Cat::Cat(void): Animal(), _brain(new Brain())
{
	std::cout << "Cat constructor." << std::endl;
	this->type = "Cat";
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
	if (this != &other)
	{
		this->type = other.getType();
/* 		if (this->_brain != NULL)
			delete this->_brain;
		t */
		for(int i = 1; i < 101; i++)
			this->_brain->setIdea(other._brain->getIdea(i), i);
	}
	return (*this);
}