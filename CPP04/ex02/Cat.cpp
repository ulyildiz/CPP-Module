#include "Cat.hpp"

Cat::Cat(void): AAnimal(), _brain(new Brain())
{
	std::cout << "Cat constructor." << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat& coppied): AAnimal(coppied), _brain(new Brain())
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