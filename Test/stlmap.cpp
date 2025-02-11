#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main(void)
{
	{
		std::vector<std::string> myMap;
		std::map<int, std::string*> myMap2;

		myMap2.insert(std::pair<int, std::string*>(1, (new std::string("A"))));

		myMap.push_back("Z");
		myMap.push_back("e");
		myMap.push_back("o");

		std::map<int, std::string*>::iterator it = myMap2.begin();
		while (it != myMap2.end())
		{
			std::cout << it._M_node << " => " << (*it).first << (*it).second << std::endl;
			it++;
		}
		delete (--it)->second;
		myMap2.erase(0);
		std::cout << "end: " << (myMap.end()).base() << std::endl;
	}

	return 0;
}
