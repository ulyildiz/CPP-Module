#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string	type;
	public:
		Animal(void);
		Animal(const Animal& coppied);
		virtual ~Animal(void);

		const std::string&	getType(void) const;
		virtual void	makeSound() const;
		Animal&	operator=(const Animal& other);
};

#endif