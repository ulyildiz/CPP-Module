#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <deque>
# include <vector>

class PmergeMe
{
	private:
		clock_t				_start;
		clock_t				_end;

		void				_startTimer(void) throw();
		void				_endTimer(void) throw();
		void				_printDuration(void) const throw();

		
		std::deque<int>		_mergeInsertion(std::deque<int> &container);
		std::size_t			_binarySearch(std::deque<int> &container, int value);
		
		std::vector<int>	_mergeInsertion(std::vector<int> &container);
		std::size_t			_binarySearch(std::vector<int> &container, int value);
		
	public:
		PmergeMe();
		PmergeMe(PmergeMe const &other);
		PmergeMe &operator=(PmergeMe const &other);
		~PmergeMe();
		
		std::size_t				 comparisonCount;
		std::vector<std::size_t> insertionOrder;
		
		void	jacobsthalNumbers(std::size_t size);
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