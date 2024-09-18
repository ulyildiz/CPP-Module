#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB {
	private:
		std::string _name;
		Weapon		*_gun;

	public:
		HumanB(std::string name);
		HumanB(std::string name, Weapon &gun);
		//~HumanB();
		void	setWeapon(Weapon &gun);
		void	attack(void);


};

#endif