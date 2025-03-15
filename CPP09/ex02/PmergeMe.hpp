#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <ctime>
# include <sstream>
# include <typeinfo>
# include <cstdlib>

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
		
		template <typename T>
		static void	parseInput(T &container, char *argv)
		{
			std::string	str(argv);
			std::stringstream	ss(str);
		
			while (ss >> str)
			{
				if (str.find_first_not_of("0123456789") != std::string::npos)
				{
					std::cerr << "Invalid input" << std::endl;
					throw std::invalid_argument("Invalid input");
				}
				container.push_back(std::atoi(str.c_str()));
			}
		}
		
		template <typename T>
		void	fordJohnson(T &main, T &pend)
		{
			_startTimer();
			makePair(main, pend);

			_endTimer();
			
			std::cout << "Time to process a range of " << main.size() << " elements with std::" << typeid(main).name();
			_printDuration(); 
		}
		
		template <typename T>
		void	makePair(T &main, T &pend)
		{
			if (main.size() <= 1)
				return ;
		
			bool	isOdd = false;
			typename T::iterator	it = main.begin();

			while (it != main.end())
			{
				if (isOdd)
				{
					pend.push_back(*it);
					it = main.erase(it);
				}
				else
				{
					++it;
				}
				isOdd = !isOdd;
			}
		}

		template <typename T>
		void	mergeInsertionSort(T &main, T &pend, int &start, int &end)
		{

		}
		template <typename T>
		void	binaryInsertion(T &container, int low, int high, int key);
		
};

#endif
