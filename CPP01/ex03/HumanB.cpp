#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
	std::cout << name << " born without any weapon" << std::endl;
}

HumanB::HumanB(std::string name, Weapon &gun)
{
	this->_name = name;
	this->_gun = &gun;
	std::cout << name << " born with a/an " << this->_gun->getType() << std::endl; 
}

void	HumanB::setWeapon(Weapon &gun)
{
	this->_gun = &gun;
	std::cout << this->_name << " got " << this->_gun->getType() << std::endl;
}

void	HumanB::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_gun->getType() << std::endl;
}
