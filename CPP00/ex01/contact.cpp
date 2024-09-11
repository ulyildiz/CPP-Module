#include "phoneBook.hpp"
#include <iostream>

std::string	get_input(std::string message)
{
	std::string	input;

	do {
		std::cout << message;
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout << "Please enter a valid input." << std::endl;
			continue ;
		}
	} while (input.empty()); //??

	return (input);
}

void	contact::displayContact(void)
{
	
}

void	contact::fillContact(int index)
{
	this->firstName = get_input("First name: ");
	this->lastName = get_input("Last name: ");
	this->nickname = get_input("Nickname: ");
	this->phoneNumber = get_input("Phone number: ");
	this->darkestSecret = get_input("Darkest secret: ");
	this->index = index;
}

int	contact::check(void)
{
	if (this->firstName.empty())
		return (1);
	return (0);
}
