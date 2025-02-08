#ifndef ITER_HPP
# define ITER_HPP

template <typename I>
void	iter(I *array, long size, void (*f)(I const &))
{
	for (long i = 0; i < size; i++)
		f(array[i]);
}

#endif