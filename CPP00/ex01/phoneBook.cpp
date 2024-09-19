#include "PhoneBook.hpp"
#include <cstdlib>

bool	checkForPrint(std::string input);

bool	PhoneBook::addContact(void)
{
	if (!(this->contactIndex % 8))
		this->contactIndex = 0;

	if (!this->_contacts[this->contactIndex].fillContact(this->contactIndex + 1))
		return (false);
	this->contactIndex++;
	return (true);
}

void	PhoneBook::displayAll(void)
{
	for (int max_user = 0; max_user < 7; max_user++)
	{
		if (!this->_contacts[max_user].check())
			this->_contacts[max_user].displayLimited();
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

bool	PhoneBook::searchContact(void)
{
	int			wantedIndex;
	std::string	input;

	if (this->_contacts[0].check())
	{
		std::cout << "The phonebook is all empty." << std::endl;
		return (true);
	}
	PhoneBook::displayAll();
	
	while (1)
	{
		std::cout << "Enter index: ";
		if (!std::getline(std::cin, input))
			break ;
		if (input.empty())
			return (true);
		if (input == "EXIT")
			break ;
		else if (!checkAllDigit(input) || !checkForPrint(input))
		{
			std::cout << "Index must consist of digits." << std::endl;
			input.clear();
			continue ;
		}
		wantedIndex = std::atoi(input.c_str());
		if (1 <= wantedIndex && wantedIndex <= 8)
		{
			this->_contacts[wantedIndex - 1].displayExtented();
			return (true);
		}
		std::cout << "Enter an index that in proper range.(1-8)" << std::endl;
	}
	return (false);
}
