#include "Bureaucrat.hpp"
#include <ctime>
#include <cstdlib>

Bureaucrat::Bureaucrat(void) : _name("White-collar"), _grade(Bureaucrat::randomGrade())
{
	std::cout << "Default constructor." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(Bureaucrat::randomGrade())
{
	std::cout << "Constructor with name." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Constructor with name and grade." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& coppied)
{
	std::cout << "Copy constructor." << std::endl;
	*this = coppied;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Default destructor." << std::endl;
}

const std::string& Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void)
{
	return (this->_grade);
}

int	Bureaucrat::randomGrade(void)
{
	std::srand(std::time(0));
	return ((std::rand() % this->_lowestGrade) + 1);
}

void	Bureaucrat::incrementGrade(void)
{
	this->_grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	this->_grade++;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	this->_grade = other._grade;
	return (*this);
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& const b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return (os);
}
