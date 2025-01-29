#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat b1("Bureaucrat 1", 42);
	Bureaucrat b2("Bureaucrat 2", 30);
	ShrubberyCreationForm s1("ShrubberyCreationForm 1");
	RobotomyRequestForm r1("RobotomyRequestForm 1");
	PresidentialPardonForm p1("PresidentialPardonForm 1");

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << s1 << std::endl;
	std::cout << r1 << std::endl;
	std::cout << p1 << std::endl;

	b1.signForm(&s1);
	b1.signForm(&r1);
	b1.signForm(&p1);

	b1.executeForm(&s1);
	b1.executeForm(&r1);
	b1.executeForm(&p1);

	return (0);
}
