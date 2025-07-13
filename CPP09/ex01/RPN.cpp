#include "RPN.hpp"
#include <cstdlib>
#include <cerrno>

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this == &other)
		return (*this);

	expressions = other.expressions;

	return (*this);
}

bool	RPN::isOperator(const std::string &s) const throw()
{
	if (s.length() != 1)
		return (false);

	if (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/')
		return (true);

	return (false);
}

bool	RPN::isNumber(const std::string &s) const throw()
{
	size_t i = 0;

	if ((s[0] == '-' || s[0] == '+') && s.length() > 1)
		i++;

	while (i < s.length())
	{
		if (!std::isdigit(s[i]))
			return (false);
		i++;
	}

	return (true);
}

bool RPN::isValidExpression(std::stringstream &iss) const throw()
{
	std::string token;

	while (iss >> token)
	{
		if (!isNumber(token) && !isOperator(token))
			return (false);
	}

	return (true);
}

void	RPN::doRPN(std::stringstream &iss)
{
	std::string token;

	while (iss >> token)
	{
//		std::cout << "Processing token: " << token << std::endl;
		if (isNumber(token))
		{
//			std::cout << "Found number: " << token << std::endl;
			long value = std::strtol(token.c_str(), NULL, 10);
			if (errno == ERANGE || value > 10)
				throw std::invalid_argument("Number out of range");

			expressions.push(static_cast<int>(value));
		}	
		else if (isOperator(token))
		{
//			std::cout << "Found operator: " << token << std::endl;
			switch (token[0])
			{
				case '+':
//					std::cout << "Adding..." << std::endl;
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
					throw std::invalid_argument("Invalid operator: " + token);
			}
		}
		else
			throw std::invalid_argument("Invalid token: " + token);
	}

	if (expressions.size() != 1)
		throw std::invalid_argument("Invalid expression");
	std::cout << expressions.top() << std::endl;
}

void	RPN::add()
{
	if (expressions.size() < 2)
		throw std::invalid_argument("Not enough operands");
	
	int a = expressions.top();
	expressions.pop();

	int b = expressions.top();
	expressions.pop();

	expressions.push(b + a);
}

void	RPN::sub()
{
	if (expressions.size() < 2)
		throw std::invalid_argument("Not enough operands");

	int a = expressions.top();
	expressions.pop();

	int b = expressions.top();
	expressions.pop();

	expressions.push(b - a);
}

void	RPN::mul()
{
	if (expressions.size() < 2)
		throw std::invalid_argument("Not enough operands");

	int a = expressions.top();
	expressions.pop();

	int b = expressions.top();
	expressions.pop();

	expressions.push(b * a);
}

void	RPN::div()
{
	if (expressions.size() < 2)
		throw std::invalid_argument("Not enough operands");

	int a = expressions.top();
	expressions.pop();

	if (a == 0)
		throw std::invalid_argument("Division by zero");

	int b = expressions.top();
	expressions.pop();
	
	expressions.push(b / a);
}
