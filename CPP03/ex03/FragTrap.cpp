#include "FragTrap.hpp"

FragTrap::FragTrap(void) 
{
	std::cout << "FragTrap Default Constructor" << std::endl;
	this->_hitPoint = 100;
	this->_energyPoint = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const std::string& name): ClapTrap(name)
{
	std::cout << "FragTrap Constructor" << std::endl;
	this->_hitPoint = 100;
	this->_energyPoint = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& coppied): ClapTrap(coppied)
{
	std::cout << "FragTrap Copy Constructor" << std::endl;
	this->_hitPoint = 100;
	this->_energyPoint = 100;
	this->_attackDamage = 30;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap Destructor" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	if (this->_hitPoint > 0)
		std::cout << this->getName() << " wants you to high-fives." << std::endl;
	else
		std::cout << this->getName() << " kinda dead." << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	this->_name = other.getName();
	this->_attackDamage = other.getAttackDamage();
	this->_energyPoint = other.getEnergyPoint();
	this->_hitPoint = other.getHitPoint();
	return (*this);
}
