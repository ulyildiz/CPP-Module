#ifndef ITER_HPP
# define ITER_HPP

template <typename A, typename F>
void	iter(A *array, long size, F f)
{
	for (long i = 0; i < size; i++)
		f(array[i]);
}

#endif