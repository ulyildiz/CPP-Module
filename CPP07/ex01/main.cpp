#include "iter.hpp"
#include <iostream>

template <typename T>
void print(T const &x)
{
	std::cout << x << std::endl;
}

template <typename T>
void	addOne(T &x)
{
	x += 1;
}


int main(void)
{
	int intArray[5] = {1, 2, 3, 4, 5};
	float floatArray[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::string stringArray[5] = {"one", "two", "three", "four", "five"};

	std::cout << "intArray: ";
	iter(intArray, 5, addOne);
	iter(intArray, 5, print);

	std::cout << "floatArray: ";
	iter(floatArray, 5, addOne);
	iter(floatArray, 5, print);

	std::cout << "stringArray: ";
	iter(stringArray, 5, addOne);
	iter(stringArray, 5, print);

	return (0);
}