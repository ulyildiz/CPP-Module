#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain* _brain;
	
	public:
		Cat(void);
		Cat(const Cat& coppied);
		~Cat(void);

		void	makeSound(void) const;
		Cat&	operator=(const Cat& other);
};

#endif