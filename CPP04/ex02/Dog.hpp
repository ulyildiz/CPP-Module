#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal {
	private:
		Brain*	_brain;

	public:
		Dog(void);
		Dog(const Dog& coppied);
		~Dog(void);

		void	makeSound(void) const;
		Dog&	operator=(const Dog& other);
};

#endif