class a
{
private:
    /* data */
public:
    a(/* args */);
    void asd()
    {
        if (this == 0)
            return ;
    }
    ~a();
};

a::a(/* args */)
{
}

a::~a()
{
}

#include <iostream>
int main(int argc, char const *argv[])
{
    a *a1 = 0;
    a1->asd();
    for (int i = -1; i < 4; i)
    {
        std::cout << i << std::endl;
        ++i++;
    }
    return 0;
}
