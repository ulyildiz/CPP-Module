#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal {
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