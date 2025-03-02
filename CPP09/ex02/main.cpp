#include "PmergeMe.hpp"
#include <deque>
#include <vector>
#include <typeinfo>

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "Usage: ./a.out <integers...>" << std::endl;
		return (1);
	}

	std::vector<int>	v;
	std::deque<int>		d;

	try {
		PmergeMe::parseInput(v, argv[1]);
		PmergeMe::parseInput(d, argv[1]);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}

	PmergeMe pm;

	std::cout << "Before:" ;
	pm.printContainer(v);

	pm.sortContainer(v);
	pm.sortContainer(d);

	std::cout << "After:" ;
	pm.printContainer(d);


	return (0);
}