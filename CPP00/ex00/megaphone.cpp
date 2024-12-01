#include <iostream>

int main(int argc, char *argv[])
{
	if (argc >= 2)
	{
		for (int j = 1; argv[j]; j++)
			for (int i = 0; argv[j][i]; i++)
				std::cout << (char)toupper(argv[j][i]);
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return 0;
}
