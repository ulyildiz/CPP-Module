#include <iostream>
#include <vector>
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
template<typename A>
class deneme
{
	A a;

public:
	typedef A::size_type val_type;

};

int main()
{
	std::vector<int> v;
	std::vector<std::string>::size_type i = 42;

	std::string str = "Hello";

	std::cout << str << std::endl;

	typename std::string::size_type s = str.size();
	std::cout << s << std::endl;
	
	typedef typename std::string::size_type n;
	n x = 42;
	return 0;
}
