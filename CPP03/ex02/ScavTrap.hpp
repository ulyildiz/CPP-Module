#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
	private:
		static unsigned int const _defEnergyPoint = 50;
		static unsigned int const _defAttackPoint = 20;
		static unsigned int const _defHitPoint = 100;

	public:
		ScavTrap(void);
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& coppied);
		~ScavTrap(void);

		void	attack(const std::string& target);
		void	guardGate(void);

		ScavTrap&	operator=(const ScavTrap& other);
};

#endif