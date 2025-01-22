#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream> 

class ClapTrap
{
	private:
		static unsigned int const _defHitpoint = 10;
		static unsigned int const _defEnergyPoint = 10; 
		static unsigned int const _defAttackDamage = 0;

	protected:
		std::string		_name;
		unsigned int	_hitPoint;
		unsigned int	_energyPoint;
		unsigned int	_attackDamage;
	
	public:
		ClapTrap(void);
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& coppied);
		~ClapTrap(void);

		std::string		getName(void) const;
		unsigned int	getHitPoint(void) const; 
		unsigned int	getEnergyPoint(void) const;
		unsigned int	getAttackDamage(void) const;

		void			attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

		ClapTrap& operator=(const ClapTrap& other);
};

#endif