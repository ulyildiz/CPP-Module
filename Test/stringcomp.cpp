#include <iostream>

int main()
{
	std::string str1 = "123-45";
	
	if (str1 > "12344")
		std::cout << "str1 is greater than 12344" << std::endl;
	
	if (str1 > "12346")
		std::cout << "str1 is greater than 12346" << std::endl;

	if (str1.compare("12345"))
		std::cout << "str1 is greater than 12345" << std::endl;

	if (str1.compare("133-06") < 0)
		std::cout << "str1 is greater than 12306 = " << str1.compare("133-06") << std::endl;
	
}