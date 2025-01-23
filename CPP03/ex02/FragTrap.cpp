#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap() 
{
	std::cout << "FragTrap Default Constructor" << std::endl;
	this->_hitPoint = FragTrap::_defHitPoint;
	this->_energyPoint = FragTrap::_defEnergyPoint;
	this->_attackDamage = FragTrap::_defAttackPoint;
}

FragTrap::FragTrap(const std::string& name): ClapTrap(name)
{
	std::cout << "FragTrap Constructor" << std::endl;
	this->_hitPoint = FragTrap::_defHitPoint;
	this->_energyPoint = FragTrap::_defEnergyPoint;
	this->_attackDamage = FragTrap::_defAttackPoint;
}

FragTrap::FragTrap(const FragTrap& coppied): ClapTrap(coppied)
{
	std::cout << "FragTrap Copy Constructor" << std::endl;
	*this = coppied;
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

void	FragTrap::attack(const std::string& target)
{
	if (this->_hitPoint > 0 && this->_energyPoint > 0)
	{	
		std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoint--;
	}
	else
		std::cout << "FragTrap " << this->_name << " is incapable of doing anything." << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	this->_name = other.getName();
	this->_attackDamage = other.getAttackDamage();
	this->_energyPoint = other.getEnergyPoint();
	this->_hitPoint = other.getHitPoint();
	return (*this);
}
