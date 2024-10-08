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
		int				getRawBits(void) const;
		void			setRawBits(int const &raw);
		float			toFloat(void) const;
		int				toInt(void) const;
};
		std::ostream&	operator<<(std::ostream &a, const Fixed &other);

#endif