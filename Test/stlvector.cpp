#include <iostream>
#include <vector>
#include <deque>

int main()
{
	std::deque<std::pair<int, int> > v;

	v.push_back(std::make_pair(1, 2));
	v.push_back(std::make_pair(3, 4));

	for (std::deque<std::pair<int, int> >::const_iterator it = v.begin(); it != v.end(); it++)
		std::cout << it->first << " " << it->second << std::endl;
	std::cout << std::endl;

	std::cout << v[0].first << " " << v[0].second << std::endl;
}
