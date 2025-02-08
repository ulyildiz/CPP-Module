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

	    enum e_type {
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
            IMPOSSIBLE,
			NON_LITERAL
		};

		e_type	_ouFlow; 
		e_type  _type;

		char	_c;
		int		_i;
		float	_f;
		double	_d;

        int isChar(const std::string& input);
        int isInt(const std::string& input);
        int isFloat(const std::string& input);
        int isDouble(const std::string& input);

        void    displayFromChar(char c);
        void    displayFromInt(int i);
        void    displayFromFloat(float f);
        void    displayFromDouble(double d);
        void    displayAllImpossible(void);
    
        void    determineType(const std::string& input);

    public:
        static void convert(const std::string& input);

        class NonLiteralException : public std::exception
        {
            public:
                const char* what() const throw();
        };

};

#endif
