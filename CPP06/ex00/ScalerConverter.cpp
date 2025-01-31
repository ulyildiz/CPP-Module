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
    return (input.length() == 1 && isprint(input[0]) ? 1 : 0);
}

void    ScalerConverter::displayChar(const std::string& input)
{
    char c = input[0];
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
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

void    ScalerConverter::displayInt(const std::string& input)
{
    int i = std::atoi(input.c_str());
    
    std::cout << "c" << std::endl;

    std::cout << "char: ";
    if (i < 32 || i > 126)
        std::cout << "Non displayable" << std::endl;
    else if ((std::numeric_limits<char>::max() < i || std::numeric_limits<char>::min() > i) || std::fmod(i, 1.0) != 0.0)
        std::cout << "impossible" << std::endl;
    else
        std::cout << "'" << static_cast<char>(i) << "'" << std::endl;

    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

int ScalerConverter::isFloat(const std::string& input)
{
    bool dot = false;

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

void    ScalerConverter::displayFloat(const std::string& input)
{
    float f = std::strtof(input.c_str(), NULL);

    std::cout << "a" << std::endl;

    std::cout << "char: ";
    if (f < 32 || f > 126)
        std::cout << "Non displayable" << std::endl;
    else if ((std::numeric_limits<char>::max() < f || std::numeric_limits<char>::min() > f) || std::fmod(f, 1.0) != 0.0)
        std::cout << "impossible" << std::endl;
    else
        std::cout << "'" << static_cast<char>(f) << "'" << std::endl;

    std::cout << "int: ";
    if (std::numeric_limits<int>::max() < f || std::numeric_limits<int>::min() > f)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(f) << std::endl;


    std::cout << "float: " << f << (std::fmod(f, 1.0f) != 0.0 ? "f" : ".0f") << std::endl;

    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

int ScalerConverter::isDouble(const std::string& input)
{
    int i = 0;
    int dot = 0;
    if (input[i] == '+' || input[i] == '-')
        i++;
    while (input[i])
    {
        if (input[i] == '.')
        {
            if (dot)
                return (0);
            dot = 1;
        }
        else if (!isdigit(input[i]))
            return (0);
        i++;
    }
    return (1);
}

void    ScalerConverter::displayDouble(const std::string& input)
{
    double d = std::strtod(input.c_str(), NULL);

    std::cout << "b" << std::endl;

    std::cout << "char: ";
    if (d < 32 || d > 126)
        std::cout << "Non displayable" << std::endl;
    else if ((std::numeric_limits<char>::max() < d || std::numeric_limits<char>::min() > d) || std::fmod(d, 1.0) != 0.0)
        std::cout << "impossible" << std::endl;
    else
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;

    std::cout << "int: ";
    if (std::numeric_limits<int>::max() < d || std::numeric_limits<int>::min() > d)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(d) << std::endl;

    std::cout << "float: ";
    if (std::numeric_limits<float>::max() < d || std::numeric_limits<float>::min() > d)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<float>(d) << (std::fmod(d, 1.0f) != 0.0 ? "f" : ".0f") << std::endl;

    std::cout << "double: " << d << (std::fmod(d, 1.0) != 0.0 ? "" : ".0") << std::endl;
}

void    ScalerConverter::convert(const std::string& input)
{
    ScalerConverter sc;

    try
    {
        if (sc.isChar(input))
            sc.displayChar(input);
        else if (sc.isInt(input))
            sc.displayInt(input);
        else if (sc.isFloat(input))
            sc.displayFloat(input);
        else if (sc.isDouble(input))
            sc.displayDouble(input);
        else
            throw NonLiteralException();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

const char* ScalerConverter::NonLiteralException::what() const throw() { return ("Non literal value"); }
