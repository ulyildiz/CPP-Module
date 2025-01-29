#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("White-collar")
{
	std::cout << "Default constructor." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name) : _name(name)
{
	std::cout << "Constructor with name." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
	std::cout << "Constructor with name and grade." << std::endl;
	if (grade < Bureaucrat::_highestGrade)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > Bureaucrat::_lowestGrade)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
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

void	Bureaucrat::incrementGrade(void)
{
	try
	{
		if (this->_grade == Bureaucrat::_highestGrade)
			throw Bureaucrat::GradeTooHighException();
		else
			std::cout << "New grade is -> " << --(this->_grade) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	Bureaucrat::decrementGrade(void)
{
	try
	{
		if (this->_grade == Bureaucrat::_lowestGrade)
			throw Bureaucrat::GradeTooLowException();
		else
			std::cout << "New grade is -> " << ++(this->_grade) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	Bureaucrat::signForm(Form* form) const
{	
	try
	{
		if (form == 0)
			throw Form::NoFormException();
		form->beSigned((*this));
		std::cout << this->_name << " signs " << form->getName() << std::endl;
	}
	catch (const Form::NoFormException& e)
	{
		std::cout << this->_name << " cannot sign the form because " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << this->_name << " cannot sign " << form->getName() << " because " << e.what() << std::endl;
	}
}

const std::string& Bureaucrat::getName(void) const { return (this->_name); }
const int&	Bureaucrat::getGrade(void) const { return (this->_grade); }

const char* Bureaucrat::GradeTooHighException::what() const throw() { return ("Grade is too high."); }
const char* Bureaucrat::GradeTooLowException::what() const throw() { return ("Grade is too low."); }

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	this->_grade = other.getGrade();
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (os);
}
