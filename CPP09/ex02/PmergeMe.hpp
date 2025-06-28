#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <ctime>
# include <sstream>
# include <typeinfo>
# include <cstdlib>
# include <deque>
# include <vector>
# include <math.h>

class PmergeMe
{
	private:
		clock_t		_start;
		clock_t		_end;

		void		_startTimer(void) throw();
		void		_endTimer(void) throw();
		void		_printDuration(void) const throw();

		template <typename T>
		void		_jacobsthalNumbers(T &container) throw()
		{
			std::size_t size = container.size();
			std::size_t n = 0;

			while (n < size)
			{
				n = (pow(2, n) - pow(-1, n)) / 3;
				jacobsthalNumbers.push_back(n);
			}
		}

		std::deque<int>	mergeInsertion(std::deque<int> &container);
		std::deque<int>	binaryInsertion(std::deque<int> &smaller, std::deque<int> &larger);

		std::vector<int> mergeInsertion(std::vector<int> &container);
		std::vector<int> binaryInsertion(std::vector<int> &smaller, std::vector<int> &larger);

	public:
		PmergeMe();
		PmergeMe(PmergeMe const &other);
		PmergeMe &operator=(PmergeMe const &other);
		~PmergeMe();

		std::size_t comparisonCount;
		std::vector<int> jacobsthalNumbers;

		void	fordJohnson(std::deque<int> &container) throw();
		void	fordJohnson(std::vector<int> &container) throw();

		template <typename T>
		void	printContainer(const T &container)
		{
			for (typename T::const_iterator it = container.begin(); it != container.end(); it++)
				std::cout << *it << " ";
			std::cout << std::endl;
		}
};

#endif