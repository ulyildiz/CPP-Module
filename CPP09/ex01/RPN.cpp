#include "RPN.hpp"
#include <cstdlib>
#include <cerrno>

RPN::RPN() {}

RPN::RPN(std::istringstream &iss)
{
	std::string token;

	while (iss >> token)
	{
		if (isOperator(token))
			op.push(token[0]);
		else if (isNumber(token))
		{
			long int n = std::strtol(token.c_str(), NULL, 10);
			if (errno == ERANGE ||n > 9)
				throw std::invalid_argument("Number out of range");

			num.push(std::atoi(token.c_str()));
		}
		else
			throw std::invalid_argument("Invalid token");
	}
}

RPN::~RPN() {}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this == &other)
		return (*this);

	num = other.num;
	op = other.op;

	return (*this);
}

bool	RPN::isOperator(const std::string &s) const
{
	if (s.length() != 1)
		return (false);

	if (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/')
		return (true);

	return (false);
}

bool	RPN::isNumber(const std::string &s) const
{
	size_t i = 0;

	if (s[0] == '-' || s[0] == '+')
		i++;

	while (i < s.length())
	{
		if (!std::isdigit(s[i]))
			return (false);
		i++;
	}

	return (true);
}

void	RPN::doRPN()
{
	while (!op.empty())
	{
		switch (op.top())
		{
			case '+':
				add();
				break;
			case '-':
				sub();
				break;
			case '*':
				mul();
				break;
			case '/':
				div();
				break;
			default:
				throw std::invalid_argument("Invalid operator");
		}
		op.pop();
	}

	if (num.size() != 1)
		throw std::invalid_argument("Invalid expression");
	std::cout << num.top() << std::endl;
}

void	RPN::add()
{
	if (num.size() < 2)
		throw std::invalid_argument("Not enough operands");
	
	int a = num.top();
	num.pop();

	int b = num.top();
	num.pop();

	num.push(b + a);
}

void	RPN::sub()
{
	if (num.size() < 2)
		throw std::invalid_argument("Not enough operands");

	int a = num.top();
	num.pop();

	int b = num.top();
	num.pop();

	num.push(b - a);
}

void	RPN::mul()
{
	if (num.size() < 2)
		throw std::invalid_argument("Not enough operands");

	int a = num.top();
	num.pop();

	int b = num.top();
	num.pop();

	num.push(b * a);
}

void	RPN::div()
{
	if (num.size() < 2)
		throw std::invalid_argument("Not enough operands");

	int a = num.top();
	num.pop();

	if (a == 0)
		throw std::invalid_argument("Division by zero");

	int b = num.top();
	num.pop();

	num.push(b / a);
}
