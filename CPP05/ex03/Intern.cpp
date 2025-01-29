#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << " Intern Default constructor." << std::endl;
}

Intern::Intern(const Intern& coppied)
{
	std::cout << " Intern Copy constructor." << std::endl;
	*this = coppied;
}

Intern::~Intern(void)
{
	std::cout << "Intern Destructor." << std::endl;
}

AForm*	Intern::makeForm(const std::string& formName, const std::string& target) const
{
	int i = 0;
	for ( ; i < this->_formCount && formName == _formTypes[i].formName; i++);
	
	this->_formTypes[i].formCreation(target);
}

Intern& Intern::operator=(const Intern& other)
{
	std::cout << "Intern Assignation operator." << std::endl;
	if (this != &other)
		 
	return (*this);
}

const char* Intern::FormNotFoundException::what() const throw() { return ("Form not found.");}
