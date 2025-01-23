#include "AAnimal.hpp"

AAnimal::AAnimal(void): _type("Unknown animal")
{
	std::cout << "AAnimal constructor." << std::endl;
	this->_type = "AAnimal";
}

AAnimal::AAnimal(const AAnimal& coppied)
{
	std::cout << "AAnimal copy constructor." << std::endl;
	*this = coppied;
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor." << std::endl;
}

const std::string&	AAnimal::getType(void) const
{
	return (this->_type);
}

AAnimal&	AAnimal::operator=(const AAnimal& other)
{
	std::cout << "AAnimal assignment operator." << std::endl;
	if (this != &other)
		this->_type = other.getType();
	return (*this);
}

