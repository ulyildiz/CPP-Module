#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called." << std::endl;
}

Fixed::Fixed(const Fixed &coppied)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = coppied;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called." << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Overloaded copy assignment operator called." << std::endl;
	if (this != &other)
		this->_value = other.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void)	const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}
