#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "WrongAnimal constructor." << std::endl;
	this->_type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& coppied)
{
	std::cout << "WrongAnimal copy constructor." << std::endl;
	*this = coppied;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor." << std::endl;
}

const std::string&	WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Some kind of Wronganimal noises." << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "WrongAnimal operator assignment." << std::endl;
	if (this != &other)
		this->_type = other.getType();
	return (*this);
}
