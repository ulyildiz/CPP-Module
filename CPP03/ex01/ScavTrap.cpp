#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap()
{
	this->_hitPoint = ScavTrap::_defHitPoint;
	this->_attackDamage = ScavTrap::_defAttackPoint;
	this->_energyPoint = ScavTrap::_defEnergyPoint;
	std::cout << "ScavTrap Default Constructor" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "ScavTrap Constructor" << std::endl;
	this->_hitPoint = ScavTrap::_defHitPoint;
	this->_attackDamage = ScavTrap::_defAttackPoint;
	this->_energyPoint = ScavTrap::_defEnergyPoint;
}

ScavTrap::ScavTrap(const ScavTrap& coppied): ClapTrap(coppied)
{
	std::cout << "ScavTrap Copy Constructor" << std::endl;
	*this = coppied;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap Destructor" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoint > 0 && this->_energyPoint > 0)
	{	
		this->_energyPoint--;
		std::cout << "ScavTrap " + this->_name + " attacks " + target + ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ScavTrap " + this->_name + " is incapable of doing anything." << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (this->_hitPoint > 0 && this->_energyPoint > 0)
		std::cout << "ScavTrap " + this->_name + " is in Gatekeeper mode." << std::endl;
	else
		std::cout << "ScavTrap " + this->_name + " is incapable of doing anything." << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	this->_name = other.getName();
	this->_attackDamage = other.getAttackDamage();
	this->_energyPoint = other.getEnergyPoint();
	this->_hitPoint = other.getHitPoint();
	return (*this);
}

