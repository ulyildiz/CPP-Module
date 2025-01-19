#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& gun) : _name(name), _gun(gun)
{
	std::cout << name << " born with a/an " << this->_gun.getType() << std::endl; 
}

void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_gun.getType() << std::endl;
}
