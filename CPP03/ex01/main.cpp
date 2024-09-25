#include "ScavTrap.hpp"

int	main(void)
{
	{
/* 		std::string ex = "cd";
		

		std::cout << /* &a << " " << &ex << std::endl;

		std::string a(ex);
		
		std::cout << &a << " " << &ex << std::endl; */
 		ScavTrap a;
		std::cout << "singleone" << std::endl;

		ScavTrap d("Scav");
		d.takeDamage(10);

		ScavTrap c(d);
		std::cout << c.getHitPoint() << std::endl; 
/* 		c.attack("CloneTrap");
		c.beRepaired(22);
		c.takeDamage(21);
		c.beRepaired(22);
		c.guardGate();
		c.guardGate();
		d.attack("Savage-clone");
		d.takeDamage(101);
		d.takeDamage(15);
		d.attack("ScavTrap-clone"); */
	}
}