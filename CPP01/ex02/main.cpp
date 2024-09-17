#include <iostream>

int main(void)
{
	std::string message = "HI THIS IS BRAIN";
	std::string &stringREF = message;
	std::string *stringPTR = &message;

	std::cout << "Address of 'message' -> " << &message << std::endl;
	std::cout << "Address of 'stringREF' -> " << &stringREF << std::endl;
	std::cout << "Address of 'stringPTR' -> " << &stringPTR << std::endl;
	std::cout << "Address in 'stringPTR' -> " << &(*stringPTR) << std::endl;

	std::cout << "Value of 'message' -> " << message << std::endl;
	std::cout << "Value of 'stringREF' -> " << stringREF << std::endl;
	std::cout << "Value of 'stringPTR' -> " << stringPTR << std::endl;

	std::cout << "Value of pointed from 'stringPTR' -> " << *stringPTR << std::endl;

	return (0);
}