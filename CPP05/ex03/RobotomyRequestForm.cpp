#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", RobotomyRequestForm::_gradeToSign, RobotomyRequestForm::_gradeToExecute), _target("default")
{
	std::cout << "RobotomyRequestForm constructor." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm("RobotomyRequestForm", RobotomyRequestForm::_gradeToSign, RobotomyRequestForm::_gradeToExecute), _target(target)
{
	std::cout << "RobotomyRequestForm target constructor." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& coppied): AForm(coppied), _target(coppied._target)
{
	std::cout << "RobotomyRequestForm copy constructor." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destructor." << std::endl;
}

const std::string& RobotomyRequestForm::getTarget(void) const { return (this->_target); }
AForm*	RobotomyRequestForm::createForm(const std::string& target) { return (new RobotomyRequestForm(target)); }

void	RobotomyRequestForm::executeAction(void) const
{
	std::cout << "Drilling noises." << std::endl;
	if (std::rand() % 2)
		std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
	else
		std::cout << this->getTarget() << " robotomization failed." << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	std::cout << "RobotomyRequestForm assignation operator." << std::endl;
	if (this != &other)
	{
	//	AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}