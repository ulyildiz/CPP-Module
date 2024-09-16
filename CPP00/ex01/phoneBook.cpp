#include "PhoneBook.hpp"
#include <cstdlib>

void	PhoneBook::PhoneBookExit(void)
{
	std::cout << "Exiting phonebook..." << std::endl;
	std::exit(0);
}

void	PhoneBook::addContact(void)
{
	if (!(this->contactIndex % 8))
		this->contactIndex = 0;

	this->contacts[this->contactIndex].fillContact(this->contactIndex + 1);
	this->contactIndex++;
}

void	PhoneBook::displayAll(void)
{
	for (int max_user = 0; max_user < 8; max_user++)
	{
		if (!this->contacts[max_user].check())
			this->contacts[max_user].displayLimited();
	}
}

int	checkAllDigit(std::string input)
{
	int	i = -1;

	while (input[++i])
	{
		if (!('0' <= input[i] && input[i] <= '9'))
			return (0);
	}
	return (1);
}

void	PhoneBook::searchContact(void)
{
	int			wantedIndex;
	std::string	input;

	if (this->contacts[0].check())
	{
		std::cout << "The phonebook is all empty." << std::endl;
		return ;
	}
	PhoneBook::displayAll();
	while (1)
	{
		std::cout << "Enter index: ";
		if (!std::getline(std::cin, input))
			std::exit(0);
		if (input.empty())
			break ;
		else if (input == "EXIT")
			this->PhoneBookExit();
		else if (!checkAllDigit(input))
		{
			std::cout << "Index must consist of digits." << std::endl;
			continue ;
		}
		wantedIndex = atoi(input.c_str());
		if (1 <= wantedIndex && wantedIndex <= 8)
		{
			this->contacts[wantedIndex - 1].displayExtented();
			break ;
		}
		std::cout << "Enter an index that in proper range.(1-8)" << std::endl;
	}
}
