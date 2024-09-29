#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal
{
	protected:
		std::string	type;
	public:
		AAnimal(void);
		AAnimal(const AAnimal& coppied);
		virtual ~AAnimal(void);

		const std::string&	getType(void) const;
		virtual void	makeSound() const = 0;
		AAnimal&	operator=(const AAnimal& other);
};

#endif