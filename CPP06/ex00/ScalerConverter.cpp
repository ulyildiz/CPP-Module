#include "ScalerConverter.hpp"

ScalerConverter::ScalerConverter() {}

ScalerConverter::ScalerConverter(const ScalerConverter &src) { *this = src; }

ScalerConverter::~ScalerConverter() {}

ScalerConverter &ScalerConverter::operator=(const ScalerConverter &src)
{
    if (this == &src)
        return (*this);
    return (*this);
}

void    ScalerConverter::convert(std::string& input)
{
    ScalerConverter sc;
    
}

const char *ScalerConverter::NonDisplayableException::what() const throw() { return ("Non displayable"); }
const char *ScalerConverter::ImpossibleException::what() const throw() { return ("impossible"); }
