#ifndef ZOMBİE_HPP
# define ZOMBİE_HPP

# include <iostream>

class Zombie {
	private:
		std::string	_name;

	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie();
		void	setName(std::string name);
		void	announce(void);
};

#endif