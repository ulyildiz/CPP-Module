#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <ctime>

class PmergeMe
{
	private:
		clock_t		_start;
		clock_t		_end;

		void		_startTimer(void) throw();
		void		_endTimer(void) throw();
		void		_printDuration(void) const throw();

	public:
		PmergeMe();
		PmergeMe(PmergeMe const &other);
		PmergeMe &operator=(PmergeMe const &other);
		~PmergeMe();

		template <typename T>
		static void	parseInput(T &container, char *argv);

		template <typename T>
		void	printContainer(const T &container);

		template <typename T>
		void	fordJohnson(T &main, T &pend);
		
		template <typename T>
		void	mergeInsertionSort(T &container);

		template <typename T>
		void	binarySearch(T &container, int low, int high, int key);
		
};

#endif
