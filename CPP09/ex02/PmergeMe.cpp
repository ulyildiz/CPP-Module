#include "PmergeMe.hpp"
#include <sstream>

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

void	PmergeMe::_startTimer() { _start = clock(); }
void	PmergeMe::_endTimer() { _end = clock(); }
void	PmergeMe::_printDuration() const { std::cout << "Duration: " << (double)(_end - _start) / CLOCKS_PER_SEC << "s" << std::endl; }

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
void	PmergeMe::sortContainer(T &container)
{
	_startTimer();


	_endTimer();
}