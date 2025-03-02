#include "Span.hpp"
#include <iostream>
#include <algorithm>
#include <numeric>

Span::Span() : _v(), _n(0) {}

Span::Span(unsigned int n) : _v(), _n(n) {}

Span::Span(Span const &other)
{
	*this = other;
}

Span::~Span()
{
	this->_v.clear();
}

void	Span::addNumber(unsigned int n)
{
	std::cout << "Size: " << this->_v.size() << std::endl;
	if (this->_v.size() == this->_n)
		throw std::out_of_range("Vector is full.");
	this->_v.push_back(n);
}

int	Span::shortestSpan(void) const
{
	if (this->_v.size() < 2)
		throw std::logic_error("Not enough elements to calculate span.");
	
	std::vector<int>	tmp = this->_v;
	std::vector<int>	diff(tmp.size());
	std::sort(tmp.begin(), tmp.end());
	std::adjacent_difference(tmp.begin(), tmp.end(), diff.begin());
	return (*std::min_element((++diff.begin()), diff.end()));
}

int	Span::longestSpan(void) const
{
	if (this->_v.size() < 2)
		throw std::logic_error("Not enough elements to calculate span.");
	return (*std::max_element(this->_v.begin(), this->_v.end()) - *std::min_element(this->_v.begin(), this->_v.end()));
}


Span&	Span::operator=(Span const &other)
{
	if (this != &other)
	{
		this->_v = other._v;
		this->_n = other._n;
	}
	return (*this);
}
