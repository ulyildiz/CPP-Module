#include "MutantStack.hpp"
#include <iostream>
# include <deque>
int	main(void)
{
	{
		MutantStack<int, std::deque<int> > mstack;

		mstack.push(5);
		mstack.push(17);
		mstack.push(3);
		mstack.push(-2);
		mstack.push(737);

		std::cout << "mstack.top() = " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "mstack.size() = " << mstack.size() << std::endl;

		MutantStack<int, std::deque<int> >::iterator it = mstack.begin();
		MutantStack<int, std::deque<int> >::iterator ite = mstack.end();

		++it;
		--it;

		std::cout << "iterator: ";
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
	
		MutantStack<int, std::deque<int> >::reverse_iterator rit = mstack.rbegin();
		MutantStack<int, std::deque<int> >::reverse_iterator rite = mstack.rend();

		std::cout << "reverse_iterator: ";
		while (rit != rite)
		{
			std::cout << *rit << " ";
			++rit;
		}
		std::cout << std::endl;

		MutantStack<int, std::deque<int> >::const_reverse_iterator crit = mstack.rbegin();
		MutantStack<int, std::deque<int> >::const_reverse_iterator crite = mstack.rend();

		std::cout << "const_reverse_iterator: ";
		while (crit != crite)
		{
			std::cout << *crit << " ";
			++crit;
		}
		std::cout << std::endl;

		MutantStack<int, std::deque<int> >::const_iterator cit = mstack.begin();
		MutantStack<int, std::deque<int> >::const_iterator cite = mstack.end();

		std::cout << "const_iterator: ";
		while (cit != cite)
		{
			std::cout << *cit << " ";
			++cit;
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

		std::cout << "iterator: ";
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;

		std::vector<int>::reverse_iterator rit = vector.rbegin();
		std::vector<int>::reverse_iterator rite = vector.rend();

		std::cout << "reverse_iterator: ";
		while (rit != rite)
		{
			std::cout << *rit << " ";
			++rit;
		}
		std::cout << std::endl;

		std::vector<int>::const_reverse_iterator crit = vector.rbegin();
		std::vector<int>::const_reverse_iterator crite = vector.rend();

		std::cout << "const_reverse_iterator: ";
		while (crit != crite)
		{
			std::cout << *crit << " ";
			++crit;
		}
		std::cout << std::endl;

		std::vector<int>::const_iterator cit = vector.begin();
		std::vector<int>::const_iterator cite = vector.end();

		std::cout << "const_iterator: ";
		while (cit != cite)
		{
			std::cout << *cit << " ";
			++cit;
		}
		std::cout << std::endl;
	}

	return (0);
}
