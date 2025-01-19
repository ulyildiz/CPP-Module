#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _gun(NULL)
{
	std::cout << name << " born without any weapon" << std::endl;
}

void	HumanB::setWeapon(Weapon &gun)
{
	this->_gun = &gun;
	std::cout << this->_name << " got " << this->_gun->getType() << std::endl;
}

void	HumanB::attack(void)
{
	if (this->_gun == NULL)
		std::cout << this->_name << " can't attack without any weapon" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_gun->getType() << std::endl;
}
