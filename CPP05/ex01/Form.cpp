#include "Form.hpp"

Form::Form(void): _name("default"), _signed(false), _gradeToSign(1), _gradeToExecute(1)
{
	std::cout << "Form default constructor." << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute): _name(name), _signed(false)
{
	std::cout << "Form constructor." << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	else
	{
		this->_gradeToSign = gradeToSign;
		this->_gradeToExecute = gradeToExecute;
	}
}

Form::Form(const Form& coppied): _name(coppied._name), _signed(coppied._signed), _gradeToSign(coppied._gradeToSign), _gradeToExecute(coppied._gradeToExecute)
{
	std::cout << "Form copy constructor." << std::endl;
}

Form::~Form(void)
{
	std::cout << "Form destructor." << std::endl;
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (this->_signed)
		throw Form::FormAlreadySignedException();
	else if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	else
	{
		std::cout << "Form signed by " << bureaucrat.getName() << std::endl;
		this->_signed = true;
	}
}

const std::string&	Form::getName(void) const { return (this->_name); }
const bool&			Form::getSigned(void) const { return (this->_signed); }
const int&			Form::getGradeToSign(void) const { return (this->_gradeToSign); }
const int&			Form::getGradeToExecute(void) const { return (this->_gradeToExecute); }

const char* Form::GradeTooHighException::what() const throw() { return ("Grade is too high."); }
const char* Form::GradeTooLowException::what() const throw() { return ("Grade is too low."); }
const char* Form::FormAlreadySignedException::what() const throw() { return ("Form is already signed."); }
const char* Form::NoFormException::what() const throw() { return ("No form to sign."); }

Form& Form::operator=(const Form& other)
{
	std::cout << "Form assignation operator." << std::endl;
	if (this != &other)
		this->_signed = other._signed;
	return (*this);
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
	std::cout << "Form insertion operator." << std::endl;
	out << "Form " << form.getName() << " is ";
	if (form.getSigned())
		out << "signed";
	else
		out << "not signed";
	out << " and requires grade " << form.getGradeToSign() << " to sign and grade " << form.getGradeToExecute() << " to execute." << std::endl;
	return (out);
}
