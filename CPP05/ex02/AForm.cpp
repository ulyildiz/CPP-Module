#include "AForm.hpp"

AForm::AForm(void): _name("default"), _signed(false), _gradeToSign(Bureaucrat::_highestGrade), _gradeToExecute(Bureaucrat::_highestGrade)
{
	std::cout << "AForm default constructor." << std::endl;
}

AForm::AForm(const std::string& name): _name(name), _signed(false), _gradeToSign(Bureaucrat::_highestGrade), _gradeToExecute(Bureaucrat::_highestGrade)
{
	std::cout << "AForm name constructor." << std::endl;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute): _name(name), _signed(false)
{
	std::cout << "AForm constructor." << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	else
	{
		this->_gradeToSign = gradeToSign;
		this->_gradeToExecute = gradeToExecute;
	}
}

AForm::AForm(const AForm& coppied): _name(coppied._name), _signed(coppied._signed), _gradeToSign(coppied._gradeToSign), _gradeToExecute(coppied._gradeToExecute)
{
	std::cout << "AForm copy constructor." << std::endl;
}

AForm::~AForm(void)
{
	std::cout << "AForm destructor." << std::endl;
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (this->_signed)
		throw AForm::FormAlreadySignedException();
	else if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	else
	{
		std::cout << "Form signed by " << bureaucrat.getName() << std::endl;
		this->_signed = true;
	}
}

void	AForm::execute(const Bureaucrat& executor) const
{
	if (!this->_signed)
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->_gradeToExecute)
		throw AForm::GradeTooLowException();
	else
	{
		std::cout << executor.getName() << " executes " << this->_name << std::endl;
		this->executeAction();
	}
}

const std::string&	AForm::getName(void) const { return (this->_name); }
const bool&			AForm::getSigned(void) const { return (this->_signed); }
const int&			AForm::getGradeToSign(void) const { return (this->_gradeToSign); }
const int&			AForm::getGradeToExecute(void) const { return (this->_gradeToExecute); }

const char* AForm::GradeTooHighException::what() const throw() { return ("Grade is too high."); }
const char* AForm::GradeTooLowException::what() const throw() { return ("Grade is too low."); }
const char* AForm::FormAlreadySignedException::what() const throw() { return ("Form is already signed."); }
const char* AForm::FormNotSignedException::what() const throw() { return ("Form is not signed."); }
const char* AForm::NoFormException::what() const throw() { return ("No form to sign."); }

AForm& AForm::operator=(const AForm& other)
{
	std::cout << "AForm assignation operator." << std::endl;
	if (this != &other)
		this->_signed = other._signed;
	return (*this);
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
	std::cout << "AForm insertion operator." << std::endl;
	out << "AForm " << form.getName() << " is ";
	if (form.getSigned())
		out << "signed";
	else
		out << "not signed";
	out << " and requires grade " << form.getGradeToSign() << " to sign and grade " << form.getGradeToExecute() << " to execute.";
	return (out);
}
