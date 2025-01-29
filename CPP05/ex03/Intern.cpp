#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << " Intern Default constructor." << std::endl;
	this->_formTypes[0].formName = "shrubbery creation";
	this->_formTypes[0].formCreation = &ShrubberyCreationForm::createForm;
	this->_formTypes[1].formName = "robotomy request";
	this->_formTypes[1].formCreation = &RobotomyRequestForm::createForm;
	this->_formTypes[2].formName = "presidential pardon";
	this->_formTypes[2].formCreation = &PresidentialPardonForm::createForm;
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
	std::cout << "Intern makeForm." << std::endl;
	try
	{
		for (int i = 0; i < this->_formCount; i++)
		{
			if (this->_formTypes[i].formName == formName)
				return (this->_formTypes[i].formCreation(target));
		}
		throw FormNotFoundException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (NULL);
}

Intern& Intern::operator=(const Intern& other)
{
	std::cout << "Intern Assignation operator." << std::endl;
	(void)other;
	return (*this);
}

const char* Intern::FormNotFoundException::what() const throw() { return ("Form not found.");}
