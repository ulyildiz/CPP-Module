#ifndef WrongCAT_HPP
# define WrongCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat(void);
		WrongCat(const WrongCat& coppied);
		~WrongCat(void);

		void	makeSound(void) const;

		WrongCat&	operator=(const WrongCat& other);
};

#endif