#include "Intern.hpp"

Intern::t_formType const formTypes[3] = {
			{"ShrubberyCreationForm", new ShrubberyCreationForm()},
			{"RobotomyRequestForm", new RobotomyRequestForm()},
			{"PresidentialPardonForm", new PresidentialPardonForm()}
};

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
	for (size_t i = 0; i < count; i++)
	{
		/* code */
	}
	
	this->formTypes[0].obj->clone(target);
}

Intern& Intern::operator=(const Intern& other)
{
	std::cout << "Intern Assignation operator." << std::endl;
	if (this != &other)
	
	return (*this);
}

const char* Intern::FormNotFoundException::what() const throw() { return ("Form not found.");}
