#include "Cat.hpp"

Cat::Cat(void): AAnimal(), _brain(new Brain())
{
	std::cout << "Cat constructor." << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat& coppied): AAnimal(coppied), _brain(NULL)
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

Cat&	Cat::operator=(const Cat& other)
{
	this->type = other.getType();
	for(int i = 0; i < 100; i++)
		this->_brain->setIdea(other._brain->getIdea(i), i);
	return (*this);
}