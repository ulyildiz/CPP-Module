#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal()
{
	std::cout << "WrongCat constructor." << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& coppied): WrongAnimal(coppied)
{
	std::cout << "WrongCat copy constructor." << std::endl;
	*this = coppied;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor." << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Meow Meow Meow Meow" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& other)
{
	std::cout << "WrongCat operator assignment." << std::endl;
	if (this != &other)
		this->_type = other.getType();
	return (*this);
}
