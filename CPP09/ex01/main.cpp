#include "RPN.hpp"
#include <sstream>

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./rpn <expression>" << std::endl;
		return (1);
	}

	std::string expr(argv[1]);
	std::istringstream iss(expr);
	
	try {
		Operations op(iss);
		op.doOperations();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}

	return (0);
}