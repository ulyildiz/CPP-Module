#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "ClapTrap Default Constructor" << std::endl;
	this->_name = "";
	this->_attackDamage = 0;
	this->_energyPoint = 10;
	this->_hitPoint = 10;
}

ClapTrap::ClapTrap(const std::string& name)
{
	std::cout << "ClapTrap Constructor" << std::endl;
	this->_name = name;
	this->_attackDamage = 0;
	this->_energyPoint = 10;
	this->_hitPoint = 10;
}

ClapTrap::ClapTrap(const ClapTrap& coppied)
{
	std::cout << "ClapTrap Copy Constructor" << std::endl;
	this->_name = coppied.getName();
	this->_attackDamage = coppied.getAttackDamage();
	this->_energyPoint = coppied.getEnergyPoint();
	this->_hitPoint = coppied.getHitPoint();
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap Destructor" << std::endl;
}

std::string	ClapTrap::getName(void) const
{
	return (this->_name);
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}

unsigned int ClapTrap::getEnergyPoint(void) const
{
	return (this->_energyPoint);
}

unsigned int ClapTrap::getHitPoint(void) const
{
	return (this->_hitPoint);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoint > 0 && this->_energyPoint > 0)
	{	
		this->_energyPoint--;
		std::cout << "ClapTrap " + this->_name + " attacks " + target + ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " + this->_name + " is incapable of doing anything." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoint > 0)
	{
		if (this->_hitPoint < amount)
			this->_hitPoint = 0;
		else
			this->_hitPoint -= amount;
		std::cout << this->_name + " took " << amount << " damage." << std::endl;
	}
	else
		std::cout << this->_name + "already dead." << std::endl;		
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoint > 0 && this->_energyPoint > 0)
	{
		this->_energyPoint--;
		this->_hitPoint += amount;
		std::cout << "ClapTrap " + this->_name + " repairs itself " << amount << " hit point(s)." << std::endl;
	}
	else
		std::cout << "ClapTrap " + this->_name + " is incapable of doing anything." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	this->_name = other.getName();
	this->_attackDamage = other.getAttackDamage();
	this->_energyPoint = other.getEnergyPoint();
	this->_hitPoint = other.getHitPoint();
	return (*this);
}
