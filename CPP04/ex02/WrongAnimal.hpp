#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	protected:
		std::string	_type;
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& coppied);
		virtual ~WrongAnimal(void);

		const std::string&	getType(void) const;
		void	makeSound() const;
		
		WrongAnimal&	operator=(const WrongAnimal& other);
};

#endif