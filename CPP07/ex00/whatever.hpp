#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename S>
void swap(S &a, S &b)
{
	S tmp = a;
	a = b;
	b = tmp;
}

template <typename MN>
MN min(const MN &a, const MN &b)
{
	return (a < b ? a : b);
}

template <typename MX>
MX max(const MX &a, const MX &b)
{
	return (a > b ? a : b);
}

#endif