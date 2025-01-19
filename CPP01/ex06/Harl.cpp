#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
	this->info();
}

void	Harl::info(void)
{
	std::cout << "[INFO]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	this->warning();
}

void	Harl::error(void)
{
	std::cout << "[ERROR]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month." << std::endl;
	this->error();
}

void	Harl::complain(std::string level)
{
	std::string	allLevel[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void		(Harl:: *f[4])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error, NULL};
	int i = 0;

	while (i < 4 && allLevel[i] != level) i++;
	
	switch (i)
	{
		case 0:
			(this->*f[i])();
			break;
		case 1:
			(this->*f[i])();
			break;
		case 2:
			(this->*f[i])();
			break;
		case 3:
			(this->*f[i])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl; 
	}
}
