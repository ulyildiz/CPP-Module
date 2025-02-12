#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template <typename T>
class Array {
	private:
		T	*_array;
		unsigned int	_size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &coppied);
		~Array();

		unsigned int	size() const;
	
		Array&	operator=(const Array& other);
		T&		operator[](unsigned int index);

		class	IndexOutOfRangeException : public std::exception {
			public:
				const char* what() const throw();
		};
};

#include "Array.tpp"

#endif