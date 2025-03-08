#include "PmergeMe.hpp"
#include <sstream>
#include <typeinfo>

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

template <typename T>
void	PmergeMe::printContainer(const T &container)
{
	for (typename T::const_iterator it = container.begin(); it != container.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	PmergeMe::_startTimer(void) throw() { _start = clock(); }
void	PmergeMe::_endTimer(void) throw() { _end = clock(); }
void	PmergeMe::_printDuration(void) const throw() { std::cout << ": " << (double)(_end - _start) / CLOCKS_PER_SEC << "s" << std::endl; }

template <typename T>
void	PmergeMe::parseInput(T &container, char *argv)
{
	std::string	str(argv);
	std::stringstream	ss(str);

	while (ss >> str)
	{
		if (str.find_first_not_of("0123456789") != std::string::npos)
		{
			std::cerr << "Invalid input" << std::endl;
			throw std::invalid_argument("Invalid input");
		}
		container.push_back(str);
	}
}

template <typename T>
void	PmergeMe::fordJohnson(T &main, T &pend)
{
	_startTimer();


	_endTimer();
	
	std::cout << "Time to process a range of " << container.size() << " elements with std::" << typeid(container).name();
	_printDuration(); 
}
