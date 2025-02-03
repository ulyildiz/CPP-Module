#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	try
	{
		Bureaucrat b1("B1", 1);
		Intern intern;
		AForm *form;

		{
			form = intern.makeForm("shrubbery creation", "target1");

			b1.signForm(form);
			b1.executeForm(form);

			delete form;
		}
		
		{
			form = intern.makeForm("robotomy request", "target2");

			b1.signForm(form);
			b1.executeForm(form);
		
			delete form;
		}

		{
			form = intern.makeForm("presidential pardon", "target3");

			b1.signForm(form);
			b1.executeForm(form);
		
			delete form;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
