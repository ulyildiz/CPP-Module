#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap: public ClapTrap {
	private:
		static unsigned int const _defAttackPoint = 30;
		static unsigned int const _defHitPoint = 100;
		static unsigned int const _defEnergyPoint = 100;

	public:
		FragTrap(void);
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& coppied);
		~FragTrap(void);

		void	highFivesGuys(void);
		void	attack(const std::string& target);

		FragTrap&	operator=(const FragTrap& other);
};

#endif