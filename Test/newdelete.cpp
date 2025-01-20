#include <iostream>
int main()
{
    std::string ***a = new std::string**[5];
    for (int i = 0; i < 5; i++)
    {
        a[i] = new std::string*[5];
        for (int j = 0; j < 5; j++)
            a[i][j] = new std::string(std::to_string(i) + "Hello" + std::to_string(j));
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            std::cout << *a[i][j] << std::endl;
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            delete a[i][j];
        delete[] a[i];
    }
    delete[] a;
}

/*     std::string **a = new std::string*[5];
    for (int i = 0; i < 5; i++)
        a[i] = new std::string ("Hello" + std::to_string(i));
    for (int i = 0; i < 5; i++)
        std::cout << *a[i] << std::endl;

    for (int i = 0; i < 5; i++)
        delete a[i];
    delete[] a; */