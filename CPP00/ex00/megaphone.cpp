#include <iostream>
#include <cctype>

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		for (int i = 0; argv[1][i]; i++)
			std::cout << (char)toupper(argv[1][i]);
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return 0;
}
