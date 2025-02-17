#include "iter.hpp"
#include <iostream>

template <typename T>
void print(T &x)
{
	std::cout << x << std::endl;
}

template <typename T>
void	addOne(T &x)
{
	x += 50;
}


int main(void)
{
	int intArray[5] = {1, 2, 3, 4, 5};
	float floatArray[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::string stringArray[5] = {"one", "two", "three", "four", "five"};

	std::cout << "intArray: " << std::endl;
	iter<int>(intArray, 5, addOne<int>);
	iter(intArray, 5, print<int>);

	std::cout << "floatArray: " << std::endl;
	iter(floatArray, 5, addOne<float>);
	iter<float, void(*)(float&)>(floatArray, 5, print<float>);

	std::cout << "stringArray: " << std::endl;
	iter(stringArray, 5, addOne<std::string>);
	iter(stringArray, 5, print<std::string>);
	
	return (0);
}