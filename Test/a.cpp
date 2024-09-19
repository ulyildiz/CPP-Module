#include <iostream>
#include <unistd.h>
#include <iomanip>
#include <streambuf>
#include <iosfwd>
int main()
{
	std::cout << std::setw(50) << "mustafa cıksana 2" << " asd" << std::endl;
	std::cout << "mustafa cıksana ";
	usleep(5);
//	std::streambuf *a = std::cout.rdbuf();
	std::cout << sizeof(ptrdiff_t);	
}