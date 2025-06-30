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

void	PmergeMe::_jacobsthalNumbers(std::size_t size)
{
	int prevJacob = 1;
	
	for (int n = 2; n < 2 + size; ++n)
	{
		int currentJacob = (std::pow(2, n) - (std::pow(-1, n))) / 3;
		insertionOrder.push_back(currentJacob);

		// Add descending numbers between current and prev
		for (int i = currentJacob - 1; i > prevJacob; --i)
			insertionOrder.push_back(i);

		prevJacob = currentJacob;
	}
}

std::deque<int>	PmergeMe::binaryInsertion(std::deque<int> &smalls, std::deque<int> &larges)
{
		
}

std::deque<int>	PmergeMe::mergeInsertion(std::deque<int> &container)
{
	std::size_t mainSize = container.size();
	std::deque<int> smaller, larger;

	if (container.size() <= 1)
		return container;

	for (std::size_t i = 0; i+1 < mainSize; i += 2)
	{
		if (container[i] < container[i+1])
		{
			smaller.push_back(container[i]);
			larger.push_back(container[i+1]);
		}
		else
		{
			smaller.push_back(container[i+1]);
			larger.push_back(container[i]);
		}
	}

	if (mainSize % 2 == 1)
		smaller.push_back(container[mainSize - 1]);

	std::deque<int> sortedLarger = mergeInsertion(larger);

	return binaryInsertion(smaller, sortedLarger);
}

void	PmergeMe::fordJohnson(std::deque<int> &container) throw()
{
	_jacobsthalNumbers(container.size());
	std::cout << "Jacobsthal numbers: ";
	printContainer(insertionOrder);

	_startTimer();
	std::deque<int> A = mergeInsertion(container);
	_endTimer();
	printContainer(A);
	std::cout << "Ford-Johnson algorithm executed";
	_printDuration();
}

std::vector<int> PmergeMe::binaryInsertion(std::vector<int> &smaller, std::vector<int> &larger)
{
	
}

std::vector<int>	PmergeMe::mergeInsertion(std::vector<int> &container)
{
	std::size_t mainSize = container.size();
	std::vector<int> smaller, larger;

	if (container.size() <= 1)
		return container;

	for (std::size_t i = 0; i+1 < mainSize; i += 2)
	{
		if (container[i] < container[i+1])
		{
			smaller.push_back(container[i]);
			larger.push_back(container[i+1]);
		}
		else
		{
			smaller.push_back(container[i+1]);
			larger.push_back(container[i]);
		}
	}

	if (mainSize % 2 == 1)
		smaller.push_back(container[mainSize - 1]);

	std::vector<int> sortedLarger = mergeInsertion(larger);
	
	return binaryInsertion(smaller, sortedLarger);
}

void	PmergeMe::fordJohnson(std::vector<int> &container) throw()
{
	_jacobsthalNumbers(container.size());

	_startTimer();
	mergeInsertion(container);
	_endTimer();
	std::cout << "Ford-Johnson algorithm executed";
	_printDuration();
}
