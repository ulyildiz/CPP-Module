#include "PmergeMe.hpp"


int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./PmergeMe \"integers...\"" << std::endl;
		return (1);
	}

	PmergeMe pmergeMe;

	std::deque<int> container;
	std::stringstream ss(argv[1]);
	int number;
	while (ss >> number)
	{
		if (ss.peek() == ' ')
			ss.ignore();
		if (number < 0)
		{			std::cerr << "Error: Negative integers are not allowed." << std::endl;
			return (1);
		}
		container.push_back(number);
	}
	if (container.empty())
	{
		std::cerr << "Error: No integers provided." << std::endl;
		return (1);
	}
	pmergeMe.printContainer(container);
	pmergeMe.fordJohnson(container);
	return (0);
}
