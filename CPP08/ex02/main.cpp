#include "MutantStack.hpp"
#include <iostream>

int	main(void)
{
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);
		mstack.push(3);
		mstack.push(-2);
		mstack.push(737);

		std::cout << "mstack.top() = " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "mstack.size() = " << mstack.size() << std::endl;

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;

		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;

	}

	{
		std::vector<int> vector;

		vector.push_back(5);
		vector.push_back(17);
		vector.push_back(3);
		vector.push_back(-2);
		vector.push_back(737);

		std::cout << "vector.top() = " << *(--vector.end()) << std::endl;
		vector.pop_back();
		std::cout << "vector.size() = " << vector.size() << std::endl;

		std::vector<int>::iterator it = vector.begin();
		std::vector<int>::iterator ite = vector.end();

		++it;
		--it;

		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
	}

	return (0);
}
