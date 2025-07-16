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
	std::string::const_iterator it = s.begin();
	bool decimalPoint = false;
	std::size_t minSize = 0;

	if (s.length() > 0 && (s[0] == '-' || s[0] == '+'))
	{
		it++;
		minSize = 1;
	}

	while (it != s.end())
	{
		if (*it == '.')
		{
			if (decimalPoint)
				return false;
			decimalPoint = true;
		}
		else if (!std::isdigit(*it))
			return false;
		++it;
	}
	return s.length() > minSize;
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
		if (isNumber(token))
		{
			long double value = std::strtold(token.c_str(), NULL);
			if (errno == ERANGE || value > 10)
				throw std::invalid_argument("Number out of range");

			expressions.push(value);
		}	
		else if (isOperator(token))
		{
			switch (token[0])
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
	
	long double a = expressions.top();
	expressions.pop();

	long double b = expressions.top();
	expressions.pop();

	expressions.push(b + a);
}

void	RPN::sub()
{
	if (expressions.size() < 2)
		throw std::invalid_argument("Not enough operands");

	long double a = expressions.top();
	expressions.pop();

	long double b = expressions.top();
	expressions.pop();

	expressions.push(b - a);
}

void	RPN::mul()
{
	if (expressions.size() < 2)
		throw std::invalid_argument("Not enough operands");

	long double a = expressions.top();
	expressions.pop();

	long double b = expressions.top();
	expressions.pop();

	expressions.push(b * a);
}

void	RPN::div()
{
	if (expressions.size() < 2)
		throw std::invalid_argument("Not enough operands");

	long double a = expressions.top();
	expressions.pop();

	if (a == 0)
		throw std::invalid_argument("Division by zero");

	long double b = expressions.top();
	expressions.pop();
	
	expressions.push(b / a);
}
