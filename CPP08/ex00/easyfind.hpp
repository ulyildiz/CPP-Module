#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <exception>

template <typename T>
typename T::iterator easyfind(T const &container, int const n)
{
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw std::exception("Not found");
	return (it);
}

#endif