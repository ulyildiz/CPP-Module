#include "PmergeMe.hpp"
#include <sstream>

bool	checkNumerical(char *argv)
{
	for (int i = 0; argv[i]; ++i)
	{
		std::cout << argv[i] << std::endl;
		if (!(isdigit(argv[i]) || ' '))
			return ( std::cout << "g: " << argv[i] << std::endl, false);
	}
	return (true);
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "Usage: ./PmergeMe \"integers...\"" << std::endl;
		return (1);
	}

	PmergeMe pmergeMe;

	std::deque<int> dequeContainer;
	std::deque<int> vectorContainer;

	for (int i = 1; i < argc; i++)
	{
		if (!checkNumerical(argv[i]))
			return (std::cout << "error" << std::endl, 1);
		std::stringstream ss(argv[i]);
		int number;
		while (ss >> number)
		{
			if (ss.peek() == ' ')
				ss.ignore();
			if (number < 0 )
				return (std::cout << "error" << std::endl, 1);
			dequeContainer.push_back(number);
			vectorContainer.push_back(number);
		}
	}

	pmergeMe.jacobsthalNumbers(vectorContainer.size());
	std::cout << "Insertion order: ";
	pmergeMe.printContainer(pmergeMe.insertionOrder);
	
	std::cout << "Before: ";
	pmergeMe.printContainer(dequeContainer);

	pmergeMe.fordJohnson(dequeContainer);
	pmergeMe.fordJohnson(vectorContainer);

	return (0);
}
