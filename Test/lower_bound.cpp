// map::lower_bound/upper_bound
#include <iostream>
#include <map>

int main ()
{
  std::map<int,int> mymap;
  std::map<int,int>::iterator itlow,itup;

  mymap[3]=20;
  mymap[4]=40;
  mymap[6]=60;
  mymap[8]=80;
  mymap[10]=100;

  itlow=mymap.lower_bound(1);  // itlow points to b
  itup=mymap.upper_bound(1);   // itup points to e (not d!)

  // print content:
  if (itlow == mymap.end())
	std::cout << "itlow is mymap.end()" << std::endl;
  if (itup == mymap.end())
	std::cout << "itup is mymap.end()" << std::endl;

  std::cout << "lower_bound is " << itlow->first << " => " << itlow->second << std::endl;
  std::cout << "upper_bound is " << itup->first << " => " << itup->second << std::endl;
  mymap.erase(itlow,itup);        // erases [itlow,itup)

  // print content:
  for (std::map<int,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  return 0;
}