#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <ctime>
# include <sstream>
# include <typeinfo>
# include <cstdlib>
# include <deque>
# include <vector>

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
		void	printContainer(const T &container)
		{
			for (typename T::const_iterator it = container.begin(); it != container.end(); it++)
				std::cout << *it << " ";
			std::cout << std::endl;
		}

		void	fordJohnson(std::deque<int> &container) throw()
		{
			_startTimer();
			// Implement the Ford-Johnson algorithm here
			_endTimer();
			std::cout << "Ford-Johnson algorithm executed";
			_printDuration();
		}

		void	fordJohnson(std::vector<int> &container) throw()
		{
			_startTimer();
			// Implement the Ford-Johnson algorithm here
			_endTimer();
			std::cout << "Ford-Johnson algorithm executed";
			_printDuration();
		}
};

#endif