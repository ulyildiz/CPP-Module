#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA {
	private:
		std::string _name;
		Weapon		*_gun;

	public:
		HumanA(std::string name, Weapon &gun);
		//~HumanA();
		void	attack();


};

#endif