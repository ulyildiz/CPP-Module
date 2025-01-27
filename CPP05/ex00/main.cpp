#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat james("James", 24);

		std::cout << "Before : " << james << std::endl;
		james.incrementGrade();
		std::cout << "After : " << james << std::endl;

		Bureaucrat sam("Sam", 1);

		std::cout << "Before : " << sam << std::endl;
		sam.decrementGrade();
		std::cout << "After : " << sam << std::endl;		

		Bureaucrat john("John", 50);
		std::cout << "john grade: " << john.getGrade() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& e) { std::cout << e.what() << std::endl; }
	catch (Bureaucrat::GradeTooLowException& e) { std::cout << e.what() << std::endl; }

	return (0);
}
