#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap a("ClapBoy");

	std::cout << "Name: " << a.getName() << std::endl;
	std::cout << "Hit Point: " << a.getHitPoint() << std::endl;
	std::cout << "Energy Point: " << a.getEnergyPoint() << std::endl;
	std::cout << "Attack Damage: " << a.getAttackDamage() << std::endl;

	{
		ClapTrap b("ClapMan");

		a.attack(b.getName());
		b.takeDamage(a.getAttackDamage());
		a.attack(b.getName());
		b.takeDamage(a.getAttackDamage());
		std::cout << a.getName() + " energy point: " << a.getEnergyPoint() << std::endl;
		std::cout << b.getName() + " hit point: " << b.getHitPoint() << std::endl;
		b.beRepaired(a.getAttackDamage());
		std::cout << b.getName() + " hit point: " << b.getHitPoint() << std::endl;
		std::cout << b.getName() + " energy point: " << b.getEnergyPoint() << std::endl;	
	}

	return (0);
}
