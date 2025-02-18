#include "Span.hpp"
#include <iostream>
#include <deque>
#include <vector>
#include <list>

int main(void)
{
	Span	sp = Span(5);
	
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	Span	sp2(5);

	sp2.addNumber(7);	

	try
	{
		std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	sp2.addNumber(3);
	sp2.addNumber(1);
	sp2.addNumber(-7);
	sp2.addNumber(-15);

	std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp2.longestSpan() << std::endl;

	try
	{
		sp2.addNumber(0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);	
}
