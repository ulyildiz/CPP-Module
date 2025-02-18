#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <exception>
# include <iostream>
# include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int n)
{
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw std::runtime_error("Not found.");
	return (it);
}

#endif