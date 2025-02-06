#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

Base * generate(void)
{
    std::srand(time(NULL));

    int i = std::rand() % 3;
    if (i == 0)
    {
        std::cout << "A generated." << std::endl;
        return (new A);
    }
    else if (i == 1)
    {
        std::cout << "B generated." << std::endl;
        return (new B);
    }
    else
    {
        std::cout << "C generated." << std::endl;
        return (new C);
    }
}

void identify(Base * p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else
        std::cout << "NOT A" << std::endl;
    if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else
        std::cout << "NOT B" << std::endl;
    if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "NOT C" << std::endl;
}

void identify(Base & p)
{
    try
    {
        A & a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "A" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << "A -> " << e.what() << std::endl;
    }
    try
    {
        B & b = dynamic_cast<B &>(p);
        (void)b;
        std::cout << "B" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << "B -> " << e.what() << std::endl;
    }
    try
    {
        C & c = dynamic_cast<C &>(p);
        (void)c;
        std::cout << "C" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << "C -> " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "Unknown type" << std::endl;
    }
}

int main()
{
    Base * p = generate();
    identify(p);
    identify(*p);
    delete p;
    return 0;
}