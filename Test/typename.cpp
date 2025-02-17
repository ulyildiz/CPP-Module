#include <iostream>

class awesome
{
public:
	awesome(int n) : _n(n) {}
	~awesome() {}
	typedef	int a;
	int getN() const { return _n; }
private:
	int _n;
};

int main()
{

	std::string str = "Hello";

	std::cout << str << std::endl;

	typename awesome::a s = str.size();
	std::cout << s << std::endl;
	
	return 0;
}
