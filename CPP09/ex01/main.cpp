#include "RPN.hpp"
#include <sstream>

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./rpn <expression>" << std::endl;
		return (1);
	}

	std::string iExpr(argv[1]);
	RPN expr;

	std::stringstream ss(iExpr);
	if (!expr.isValidExpression(ss))
	{
		std::cerr << "Invalid expression" << std::endl;
		return (1);
	}

	try {
		std::stringstream ss2(iExpr);
		expr.doRPN(ss2);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}

	return (0);
}
