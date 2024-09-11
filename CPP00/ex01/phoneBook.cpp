#include "phoneBook.hpp"
#include <iostream>
#include <stdlib.h>

void	phoneBook::phoneBookExit(void)
{
	std::cout << "Exiting phonebook..." << std::endl;
	exit(0);
}

void	phoneBook::addContact(void)
{
	if (!(this->contactIndex % 8))
		this->contactIndex = 0;

	this->contacts[this->contactIndex].fillContact(this->contactIndex + 1);
	this->contactIndex++;
}

void	phoneBook::displayAll(void)
{
	std::cout << "as" << std::endl;
}

void	phoneBook::searchContact(void)
{
	int			wantedIndex;
	std::string	input;

	if (this->contacts[0].check())
	{
		std::cout << "The phonebook is all empty." << std::endl;
		return ;
	}
	phoneBook::displayAll();	

	do {
		std::cout << "Enter index: ";
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout << "Enter proper index.(1-8)" << std::endl;
			continue ;
		} //isalpha?
		wantedIndex = atoi(input.c_str());
		if (!(1 <= wantedIndex && wantedIndex <= 8))
		{
			std::cout << "Enter proper index.(1-8)" << std::endl;
			continue ;
		}
		//this->contacts[wantedIndex - 1].printContact();
	} while (input.empty());
}
