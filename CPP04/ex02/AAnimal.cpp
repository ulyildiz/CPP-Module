#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
	std::cout << "AAnimal constructor." << std::endl;
	this->type = "AAnimal";
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
	return (this->type);
}

/* void	AAnimal::makeSound(void) const
{
	std::cout << "Some kind of Aanimal noises." << std::endl;
}
 */
AAnimal&	AAnimal::operator=(const AAnimal& other)
{
	this->type = other.getType();
	return (*this);
}

