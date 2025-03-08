#include "PmergeMe.hpp"
#include <deque>
#include <vector>

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "Usage: ./a.out <integers...>" << std::endl;
		return (1);
	}

	std::vector<int>	v_main;
	std::vector<int>	v_pend;
	std::deque<int>		d_main;
	std::deque<int>		d_pend;

	try {
		PmergeMe::parseInput(v_main, argv[1]);
		PmergeMe::parseInput(d_main, argv[1]);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}

	PmergeMe pm;

	std::cout << "Before:" ;
	pm.printContainer(v_main);

	pm.fordJohnson(v_main, v_pend);
	pm.fordJohnson(d_main, d_pend);

	std::cout << "After:" ;
	pm.printContainer(d_main);

	return (0);
}
