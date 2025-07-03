#include "PmergeMe.hpp"
#include <cmath>
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
void	PmergeMe::_printDuration(void) const throw() { std::cout << ": " << std::fixed << std::setprecision(6) << (double)(_end - _start) / CLOCKS_PER_SEC  << "s" << std::endl; }

void	PmergeMe::jacobsthalNumbers(std::size_t size)
{
	std::size_t prevJacob = 1;
	
	for (std::size_t n = 2; prevJacob < size; ++n)
	{
		std::size_t currentJacob = (std::pow(2, n) - (std::pow(-1, n))) / 3;
		insertionOrder.push_back(currentJacob);

		for (std::size_t i = currentJacob - 1; i > prevJacob; --i)
			insertionOrder.push_back(i);

		prevJacob = currentJacob;
	}
}

std::size_t PmergeMe::_binarySearch(std::deque<int> &container, int value)
{
	std::size_t left = 0;
	std::size_t right = container.size();

	while (left < right)
	{
		std::size_t mid = left + (right - left) / 2;
		if (container[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	return (left);
}

std::deque<int>	PmergeMe::_mergeInsertion(std::deque<int> &container)
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

	std::deque<int> sortedLarger = _mergeInsertion(larger);

	for (std::size_t i = 0; i < insertionOrder.size(); ++i)
	{
		if (insertionOrder[i] - 1 >= smaller.size())
			continue;
		int value = smaller[insertionOrder[i] - 1];
		std::size_t pos = _binarySearch(sortedLarger, value);
		if (pos == sortedLarger.size())
			sortedLarger.push_back(value);
		else
			sortedLarger.insert(sortedLarger.begin() + pos, value);
	}
	return (sortedLarger);
}

void	PmergeMe::fordJohnson(std::deque<int> &container) throw()
{
	_startTimer();
	std::deque<int> A = _mergeInsertion(container);
	_endTimer();

	std::cout << "After(deque): ";
	printContainer(A);
	std::cout << "Ford-Johnson algorithm executed";
	_printDuration();
}

std::size_t PmergeMe::_binarySearch(std::vector<int> &container, int value)
{
	std::size_t left = 0;
	std::size_t right = container.size();

	while (left < right)
	{
		std::size_t mid = left + (right - left) / 2;
		if (container[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	return (left);
}

std::vector<int>	PmergeMe::_mergeInsertion(std::vector<int> &container)
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

	std::vector<int> sortedLarger = _mergeInsertion(larger);

	for (std::size_t i = 0; i < insertionOrder.size(); ++i)
	{
		if (insertionOrder[i] - 1 >= smaller.size())
			continue;

		int value = smaller[insertionOrder[i] - 1];
		std::size_t pos = _binarySearch(sortedLarger, value);
		if (pos == sortedLarger.size())
			sortedLarger.push_back(value);
		else
			sortedLarger.insert(sortedLarger.begin() + pos, value);
	}
	return (sortedLarger);
}

void	PmergeMe::fordJohnson(std::vector<int> &container) throw()
{
	_startTimer();
	std::vector<int> A = _mergeInsertion(container);
	_endTimer();

	std::cout << "After(vector): ";
	printContainer(A);
	std::cout << "Ford-Johnson algorithm executed";
	_printDuration();
}

