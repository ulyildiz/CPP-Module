#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <ctime>
# include <sstream>
# include <cstdlib>
# include <deque>
# include <vector>
# include <cmath>

class PmergeMe
{
	private:
		clock_t		_start;
		clock_t		_end;

		void		_startTimer(void) throw();
		void		_endTimer(void) throw();
		void		_printDuration(void) const throw();

		void		_jacobsthalNumbers(std::size_t size);

		std::deque<int>	mergeInsertion(std::deque<int> &container);
		std::deque<int>	binaryInsertion(std::deque<int> &smalls, std::deque<int> &larges);
		std::size_t PmergeMe::binarySearch(std::deque<int> &container, int value);

		std::vector<int> mergeInsertion(std::vector<int> &container);
		std::vector<int> binaryInsertion(std::vector<int> &smaller, std::vector<int> &larger);

	public:
		PmergeMe();
		PmergeMe(PmergeMe const &other);
		PmergeMe &operator=(PmergeMe const &other);
		~PmergeMe();

		std::size_t comparisonCount;
		std::vector<int> insertionOrder;

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