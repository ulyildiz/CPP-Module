#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class Span {
	private:
		std::vector<int>	_v;
		unsigned int		_n;

	public:
		Span();
		Span(unsigned int n);
		Span(Span const &other);
		~Span();

		void	addNumber(unsigned int n);
		int		shortestSpan(void) const;
		int		longestSpan(void) const;

		Span& operator=(Span const &other);
};

#endif