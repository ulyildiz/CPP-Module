#ifndef SCALERCONVERTER_HPP
# define SCALERCONVERTER_HPP

# include <iostream>

class ScalerConverter
{
    private:
        ScalerConverter();
        ScalerConverter(const ScalerConverter &src);
        ~ScalerConverter();
        ScalerConverter &operator=(const ScalerConverter &src);

    public:
        void        convertDouble(double input);
        void        convertFloat(float input);
        void        convertInt(int input);
        void        convertChar(char *input);
        static void convert(std::string& input);

        class ImpossibleException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        class NonDisplayableException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

}

#endif