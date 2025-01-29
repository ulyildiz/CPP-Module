#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("ShrubberyCreationForm", ShrubberyCreationForm::_gradeToSign, ShrubberyCreationForm::_gradeToExecute), _target("default")
{
	std::cout << "ShrubberyCreationForm default constructor." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): AForm("ShrubberyCreationForm", ShrubberyCreationForm::_gradeToSign, ShrubberyCreationForm::_gradeToExecute), _target(target)
{
	std::cout << "ShrubberyCreationForm target constructor." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& coppied): AForm(coppied), _target(coppied._target)
{
	std::cout << "ShrubberyCreationForm copy constructor." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destructor." << std::endl;
}

const std::string&	ShrubberyCreationForm::getTarget(void) const { return (this->_target); }
AForm*	ShrubberyCreationForm::createForm(const std::string& target) { return (new ShrubberyCreationForm(target)); }

void	ShrubberyCreationForm::executeAction(void) const
{
	std::ofstream	outputFile((this->_target + "_shrubbery").c_str(), std::ios::out | std::ios::trunc | std::ios::app);

	if (!outputFile.is_open())
		throw std::ofstream::failure("Error: could not open file.");
	else
	{
		outputFile << 		"          .     .  .      +     .      .          .\n"
		"     .       .      .     #       .           .\n"
		"        .      .         ###            .      .      .\n"
		"      .      .   \"#:. .:##\"##:. .:#\"  .      .\n"
		"          .      . \"####\"###\"####\"  .\n"
		"       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       .\n"
		"  .             \"#########\"#########\"        .        .\n"
		"        .    \"#:.  \"####\"###\"####\"  .:#\"   .       .\n"
		"     .     .  \"#######\"\"##\"##\"\"#######\"                  .\n"
		"                .\"##\"#####\"#####\"##\"           .      .\n"
		"    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     .\n"
		"      .     \"#######\"##\"#####\"##\"#######\"      .     .\n"
		"    .    .     \"#####\"\"#######\"\"#####\"    .      .\n"
		"            .     \"      000      \"    .     .\n"
		"       .         .   .   000     .        .       .\n"
		".. .. ..................O000O........................ ...... ...\n";
		outputFile.close();
	}
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << "ShrubberyCreationForm assignation operator." << std::endl;
	if (this != &other)
	{
	//	AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}
