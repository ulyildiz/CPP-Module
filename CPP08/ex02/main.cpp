#include "MutantStack.hpp"
#include <iostream>

int	main(void)
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

	std::vector<int> vec;

	for (int i = 0; i < 10; i++)
		vec.push_back(i);

	std::vector<int>::iterator it2 = vec.begin();
	std::vector<int>::iterator ite2 = vec.end();

	while (it2 != ite2)
	{
		std::cout << *it2 << " ";
		++it2;
	}
	std::cout << std::endl;

	return (0);
}
