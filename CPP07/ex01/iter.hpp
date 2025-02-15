#ifndef ITER_HPP
# define ITER_HPP

template <typename A>
void	iter(A *array, long size, void (*f)(A &))
{
	for (long i = 0; i < size; i++)
		f(array[i]);
}

#endif