 #include <iostream>
#include <utility>  // Needed for std::declval

/*template <typename T, typename = decltype(std::declval<T>().value)>
void foo(T t)
{

	std::cout << "foo" <<  std::endl;
}

class Test
{
public:
	Test(): value(0) {}
	int value;	
};

class Test2
{
public:
	Test2(): value(46) {}
	char value;
};

class Test3
{
public:
	Test3(): valu(0) {}
	int valu;
};

int main()
{

	foo<Test>(Test());
	foo<Test2>(Test2());
	foo<Test3>(Test3());
	return 0;
} */

/* template <typename T>
struct has_typedef_foobar {
  // Types "yes" and "no" are guaranteed to have different sizes,
  // specifically sizeof(yes) == 1 and sizeof(no) == 2.
  typedef char yes[1];
  typedef char no[2];

  template <typename C>
  static yes& test(typename C::foobar*);

  template <typename>
  static no& test(...);

  // If the "sizeof" of the result of calling test<T>(nullptr) is equal to
  // sizeof(yes), the first overload worked and T has a nested type named
  // foobar.
  static const bool value = (sizeof(test<T>()) == sizeof(yes));
};

struct foo {
  typedef float foobar;
};

int main() {
  std::cout << std::boolalpha;
  std::cout << has_typedef_foobar<int>::value << std::endl;  // Prints false
  std::cout << has_typedef_foobar<foo>::value << std::endl;  // Prints true
  return 0;
} */

/* template <typename T>
class a: public T
{
public:
	a() {}
	~a() {}

}; */
