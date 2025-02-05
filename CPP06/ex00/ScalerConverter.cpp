#include "ScalerConverter.hpp"
#include <cstdlib>
#include <cmath>
#include <limits>

ScalerConverter::ScalerConverter() {}

ScalerConverter::ScalerConverter(const ScalerConverter &src) { *this = src; }

ScalerConverter::~ScalerConverter() {}

ScalerConverter &ScalerConverter::operator=(const ScalerConverter &src)
{
    if (this == &src)
        return (*this);
    return (*this);
}

int ScalerConverter::isChar(const std::string& input)
{
    return (input.length() == 1 && isascii(input[0]) ? 1 : 0);
}

int ScalerConverter::isInt(const std::string& input)
{
    int i = 0;

    if (input[i] == '+' || input[i] == '-')
        i++;
    while (input[i])
    {
        if (!isdigit(input[i]))
            return (0);
        i++;
    }
    return (1);
}

int ScalerConverter::isFloat(const std::string& input)
{
    bool dot = false;

    if (input == "nanf" || input == "+inff" || input == "-inff" || input == "inff")
        return (1);

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
        return (1);
    return (0);
}


int ScalerConverter::isDouble(const std::string& input)
{
    bool dot = false;

    if (input == "nan" || input == "+inf" || input == "-inf" || input == "inf")
        return (1);

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
    return (1);
}

void	ScalerConverter::determineType(const std::string& input)
{
	if (isChar(input))
		_type = CHAR;
	else if (isInt(input))
		_type = INT;
	else if (isFloat(input))
		_type = FLOAT;
	else if (isDouble(input))
		_type = DOUBLE;
	else
		_type = NON_LITERAL;
}

void	ScalerConverter::displayFromChar(char c)
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

void	ScalerConverter::displayFromInt(int i)
{
	std::cout << "char: ";
	if (isprint(i))
		std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
	else if (isascii(i))
		std::cout << "Non displayable" << std::endl;
	else
        std::cout << "impossible" << std::endl;
    
    std::cout << "int: ";
    if (i > std::numeric_limits<int>::max() || i < std::numeric_limits<int>::min())
        std::cout << "impossible" << std::endl;
    else
    {
        std::cout << i << std::endl;
    }
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void    ScalerConverter::displayFromFloat(float f)
{
    bool    hasDecimal = std::fmod(f, 1.0f);

	std::cout << "char: ";
	if (31 < f && f < 127 && !hasDecimal)
		std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
	else if (0 <= f && f <= 255 && !hasDecimal)
		std::cout << "Non displayable" << std::endl;
	else
        std::cout << "impossible" << std::endl;

    std::cout << "int: ";
    if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min() || isnan(f))
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(f) << std::endl;

    std::cout << "float: " << f << (hasDecimal ? "f" : ".0f") << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void    ScalerConverter::displayFromDouble(double d)
{
    bool    hasDecimal = std::fmod(d, 1.0);

	std::cout << "char: ";
	if (d < 127 && d > 31 && !hasDecimal)
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
	else if (0 <= d && d <= 255 && !hasDecimal)
		std::cout << "Non displayable" << std::endl;
	else
        std::cout << "impossible" << std::endl;

    std::cout << "int: ";
    if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min() || isnan(d))
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(d) << std::endl;

    std::cout << "float: " << static_cast<float>(d) << (hasDecimal ? "f" : ".0f") << std::endl;
    std::cout << "double: " << d << std::endl;
}

void    ScalerConverter::convert(const std::string& input)
{
    ScalerConverter sc;

    try
    {
		sc.determineType(input);
        switch	(sc._type)
		{
			case CHAR:
				sc.displayFromChar(input.c_str()[0]);
				break;
			case INT:
				sc.displayFromInt(std::atoi(input.c_str()));
				break;
			case FLOAT:
				sc.displayFromFloat(std::strtof(input.c_str(), NULL));
				break;
			case DOUBLE:
				sc.displayFromDouble(std::strtod(input.c_str(), NULL));
				break;
			case NON_LITERAL:
				throw ScalerConverter::NonLiteralException();
				break;
		}
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

const char* ScalerConverter::NonLiteralException::what() const throw() { return ("Non literal value"); }
