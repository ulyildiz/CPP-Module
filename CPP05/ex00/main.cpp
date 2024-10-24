#include "Bureaucrat.hpp"

int mmain(void)
{
	try
	{
		Bureaucrat james("James", 24);

		std::cout << "Before gradePlus(): " << james << std::endl;
		james.incrementGrade();
		std::cout << "After gradePlus(): " << james << std::endl;

		Bureaucrat sam("Sam", 1);

		std::cout << "Before gradeMinus(): " << sam << std::endl;
		sam.incrementGrade();
	} 
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
