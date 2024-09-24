#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
		int					_value;
		static const int	_bits = 8;

	public:
		Fixed(void);
		Fixed(const int &value);
		Fixed(const float &value);
		Fixed(const Fixed &coppied);
		~Fixed(void);
		Fixed&			operator=(const Fixed &other); 
		Fixed& 			operator++();
		Fixed& 			operator--();
		Fixed 			operator++(int);
		Fixed 			operator--(int);
		Fixed 			operator+(const Fixed& other);
		Fixed 			operator-(const Fixed& other);
		Fixed 			operator*(const Fixed& other);
		Fixed 			operator/(const Fixed& other);
		bool 			operator>(const Fixed& other);
		bool 			operator<(const Fixed& other);
		bool 			operator>=(const Fixed& other);
		bool 			operator<=(const Fixed& other);
		bool 			operator==(const Fixed& other);
		bool 			operator!=(const Fixed& other);
		int				getRawBits(void) const;
		void			setRawBits(int const &raw);
		float			toFloat(void) const;
		int				toInt(void) const;
		static Fixed& min(Fixed &a, Fixed &b);
    	static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& min(const Fixed &a, const Fixed &b);
		static const Fixed& max(const Fixed &a, const Fixed &b);

};
		std::ostream&	operator<<(std::ostream &a, const Fixed &other);

#endif