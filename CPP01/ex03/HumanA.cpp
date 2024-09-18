#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &gun)
{
	this->_gun = &gun;
	this->_name = name;
	std::cout << name << " born with a/an " << this->_gun->getType() << std::endl; 
}

void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_gun->getType() << std::endl;
}
