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


        int isChar(const std::string& input);
        int isInt(const std::string& input);
        int isFloat(const std::string& input);
        int isDouble(const std::string& input);

        void displayChar(const std::string& input);
        void displayInt(const std::string& input);
        void displayFloat(const std::string& input);
        void displayDouble(const std::string& input);
    
    public:
        static void convert(const std::string& input);

        class NonLiteralException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

};

#endif
