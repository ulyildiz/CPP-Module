#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called." << std::endl;
}

Fixed::Fixed(const int &value)
{
	this->_value = value << this->_bits;
}

Fixed::Fixed(const float &value)
{
	this->_value = roundf(value * (1 << this->_bits));
}

Fixed::Fixed(const Fixed &coppied)
{
	std::cout << "Copy constructor called." << std::endl;
	this->_value = coppied.getRawBits();
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called." << std::endl;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_value / (float)(1 << this->_bits));
}

int	Fixed::toInt(void) const
{
	return (this->_value >> this->_bits); // staticcast ?
}

int	Fixed::getRawBits(void)	const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const &raw)
{
	this->_value = raw;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() >= b.getRawBits())
		return a;
	return b;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() >= b.getRawBits())
		return a;
	return b;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Overloaded copy assignment operator called." << std::endl;
	if (this != &other)
		this->_value = other.getRawBits();
	return (*this);
}

Fixed&	Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

Fixed&	Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator++(int)//düzgün çalışıcak mı?
{
	Fixed	tmp = *this;
	this->_value++;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	this->_value--;
	return (tmp);
}

Fixed	Fixed::operator+(const Fixed& other)
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& other)
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& other)
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& other)
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

bool	Fixed::operator>(const Fixed& other)
{
	return (this->_value > other.getRawBits());
}

bool	Fixed::operator<(const Fixed& other)
{
	return (this->_value < other.getRawBits());
}

bool	Fixed::operator>=(const Fixed& other)
{
	return (this->_value >= other.getRawBits());
}

bool	Fixed::operator<=(const Fixed& other)
{
	return (this->_value <= other.getRawBits());
}

bool	Fixed::operator==(const Fixed& other)
{
	return (this->_value == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed& other)
{
	return (this->_value != other.getRawBits());
}

std::ostream&	operator<<(std::ostream &a, const Fixed &other)
{
	std::cout << "Overloaded insertion operator called." << std::endl;
	a << other.toFloat();
	return (a);
}
