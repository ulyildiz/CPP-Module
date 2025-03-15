#include "PmergeMe.hpp"
#include <iomanip>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const &other)
{
	*this = other;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &other)
{
	(void)other;
	return *this;
}

PmergeMe::~PmergeMe() {}

void	PmergeMe::_startTimer(void) throw() { _start = clock(); }
void	PmergeMe::_endTimer(void) throw() { _end = clock(); }
void	PmergeMe::_printDuration(void) const throw() { std::cout << ": " << std::fixed << std::setprecision(6) << (double)(_end - _start) / CLOCKS_PER_SEC * 1000000 << "us" << std::endl; }

