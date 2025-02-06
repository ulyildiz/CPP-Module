#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

struct Data {
    std::string str;
    int         i;
    float       f;

    Data(std::string str, int i, float f);
};

#endif