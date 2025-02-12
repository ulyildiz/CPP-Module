#include "ScalarConverter.hpp"
#include <cstdlib>
#include <limits>
#include <cmath>
#include <errno.h>
#include <iomanip>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src) { *this = src; }

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
    if (this == &src)
        return (*this);
    return (*this);
}

int ScalarConverter::isChar(const std::string& input)
{
	if (input.length() == 1 && isascii(input[0]))
	{
		this->_c = input.c_str()[0];
		return (1);
	}
	this->_ouFlow = CHAR;
    return (0);
}

int ScalarConverter::isInt(const std::string& input)
{
    std::string::size_type i = 0;
    std::string maxIntStr = "2147483647";
    std::string minIntStr = "2147483648";
    bool isNegative = false;

    if (input[i] == '+' || input[i] == '-')
    {
        isNegative = (input[i] == '-');
        i++;
    }

    while (i < input.length() && input[i] == '0') 
        i++;

    std::string numStr = input.substr(i);

    for (std::string::size_type j = 0; j < numStr.length(); j++)
    {
        if (!std::isdigit(numStr[j]))
            return (0);
    }

    if (numStr.length() > maxIntStr.length())
        return (_ouFlow = INT, 0);
    else if (numStr.length() == maxIntStr.length())
    {
        for (std::string::size_type i = 0; i < maxIntStr.length(); i++)
        {
            if (numStr[i] > (isNegative ? minIntStr[i] : maxIntStr[i]))
                return (_ouFlow = INT, 0);
		}
    }
	_i = std::atoi(input.c_str());
    return (1);
}

int ScalarConverter::isFloat(const std::string& input)
{
    bool dot = false;

    if (input == "nanf" || input == "+inff" || input == "-inff" || input == "inff")
        return (_f = std::strtof(input.c_str(), NULL), 1);

    for (std::string::size_type i = 0; i < input.length() - 1; i++)
    {
        if (input[i] == '+' || input[i] == '-')
            i++;
        if (input[i] == '.')
        {
            if (dot)
                return (0);
            dot = true;
        }
        else if (!isdigit(input[i]))
            return (0);
    }
    if (input[input.length() - 1] == 'f')
    {
		_f = std::strtof(input.c_str(), NULL);
		if (errno == ERANGE)
		{
			_ouFlow = FLOAT;
			errno = 0;
			return (0);
		}
	    return (1);
	}
	return (0);
}


int ScalarConverter::isDouble(const std::string& input)
{
    bool dot = false;

	if (input == "nan" || input == "+inf" || input == "-inf" || input == "inf")
		return (_d = std::strtod(input.c_str(), NULL), 1);

    for (std::string::size_type i = 0; i < input.length() - 1; i++)
    {
        if (input[i] == '+' || input[i] == '-')
            i++;
        if (input[i] == '.')
        {
            if (dot)
                return (0);
            dot = true;
        }
        else if (!isdigit(input[i]))
            return (0);
	}

	if (input[input.length()] != 'f' && isdigit(input[input.length()]) && input[input.length()] != '.')
		return (0);
	else
	{
		_d = std::strtod(input.c_str(), NULL);
		if (errno == ERANGE)
		{
			std::cout << _d << std::endl;
			_ouFlow = DOUBLE;
			_type = IMPOSSIBLE;
			return (0);
		}
		return (1);
	}
    return (0);
}

void	ScalarConverter::determineType(const std::string& input)
{
	if (isChar(input))
		_type = CHAR;
	else if (isInt(input))
		_type = INT;
	else if (isFloat(input))
		_type = FLOAT;
	else if (isDouble(input))
		_type = DOUBLE;
	else if (_type != IMPOSSIBLE)
        _type = NON_LITERAL;
}

void	ScalarConverter::displayFromChar(char c)
{
	std::cout << "char: ";
	if (isprint(c))
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void	ScalarConverter::displayFromInt(int i)
{
	std::cout << "char: ";
	if (31 < i && i < 127)
		std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
	else if (0 <= i && i <= 255)
		std::cout << "Non displayable" << std::endl;
	else
        std::cout << "impossible" << std::endl;
    
    std::cout << "int: ";
    if (_ouFlow == INT)
        std::cout << "impossible" << std::endl;
    else
		std::cout << i << std::endl;
	
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void    ScalarConverter::displayFromFloat(float f)
{
    bool    hasDecimal = std::fmod(f, 1.0f);

	std::cout << "char: ";
	if (31 < f && f < 127)
		std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
	else if (0 <= f && f <= 255)
		std::cout << "Non displayable" << std::endl;
	else
        std::cout << "impossible" << std::endl;

    std::cout << "int: ";
    if (_ouFlow == INT || std::isnan(f) || std::numeric_limits<int>::max() < f || f < std::numeric_limits<int>::min())
        std::cout << "impossible" << std::endl;
    else
		std::cout << static_cast<int>(f) << std::endl;

	std::cout << "float: " << f << (hasDecimal ? "f" : ".0f") << std::endl;
    std::cout << "double: " << static_cast<double>(f) << (std::fmod(static_cast<double>(f), 1.0f) ? "" : ".0") << std::endl;
}

void    ScalarConverter::displayFromDouble(double d)
{
    bool    hasDecimal = std::fmod(d, 1.0);

	std::cout << "char: ";
	if (31 < d && d < 127)
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
	else if (0 <= d && d <= 255)
		std::cout << "Non displayable" << std::endl;
	else
        std::cout << "impossible" << std::endl;

    std::cout << "int: ";
    if (_ouFlow == INT || std::isnan(d) || std::numeric_limits<int>::max() < d || d < std::numeric_limits<int>::min())
        std::cout << "impossible" << std::endl;
    else
		std::cout << static_cast<int>(d) << std::endl;

	std::cout << "float: ";
    if ((_ouFlow == FLOAT || std::numeric_limits<float>::max() < d || d < -std::numeric_limits<float>::max()) && !std::isinf(d))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<float>(d) << (std::fmod(static_cast<float>(d), 1.0f) ? "f" : ".0f") << std::endl;
	std::cout << "double: " << d << (hasDecimal ? "" : ".0") << std::endl;
}

void    ScalarConverter::displayAllImpossible(void)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

void    ScalarConverter::convert(const std::string& input)
{
    ScalarConverter sc;

    try
    {
		std::cout << std::setprecision(309);
		sc.determineType(input);
        switch	(sc._type)
		{
			case CHAR:
				std::cout << "enter char: " << std::endl;
				sc.displayFromChar(sc._c);
				break ;
			case INT:
				std::cout << "enter int: " << std::endl;
				sc.displayFromInt(sc._i);
				break;
			case FLOAT:
				std::cout << "enter float: " << std::endl;
				sc.displayFromFloat(sc._f);
				break;
			case DOUBLE:
				std::cout << "enter double: " << std::endl;
				sc.displayFromDouble(sc._d);
				break;
			case IMPOSSIBLE:
                sc.displayAllImpossible();
                break;
            default:
				throw ScalarConverter::NonLiteralException();
				break;
		}
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

const char* ScalarConverter::NonLiteralException::what() const throw() { return ("Non literal value"); }


// ./convert 9 && ./convert 57
// ./convert "" && ./convert 0
// ./convert 2.f && ./convert 4a
// ./convert 4.a && ./convert 1111111