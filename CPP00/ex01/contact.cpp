#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

std::string	get_input(std::string message)
{
	std::string	input;

	do {
		std::cout << message;
		if (!std::getline(std::cin, input))
			std::exit(0);
		if (input.empty())
		{
			std::cout << "Please enter a valid input." << std::endl;
			continue ;
		}
	} while (input.empty()); //??

	return (input);
}

std::string	truncateAndFix(std::string information)
{
	if (information.empty())
		return ("-");
	if (information.length() > 10)
		return (information[9] = '.', information.substr(0, 10));
	return (information);
}

void	Contact::displayLimited(void)
{
	std::cout << std::setw(10) << this->index << "|";
	std::cout << std::setw(10) << truncateAndFix(this->firstName) << "|";
	std::cout << std::setw(10) << truncateAndFix(this->lastName) << "|";
	std::cout << std::setw(10) << truncateAndFix(this->nickname) << std::endl;
}

void	Contact::displayExtented(void)
{
	std::cout << "First name: " << this->firstName << std::endl;
	std::cout << "Last name: " << this->lastName << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone number: " << this->phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << this->darkestSecret << std::endl;
}

void	Contact::fillContact(int index)
{
	this->firstName = get_input("First name: ");
	this->lastName = get_input("Last name: ");
	this->nickname = get_input("Nickname: ");
	this->phoneNumber = get_input("Phone number: ");
	this->darkestSecret = get_input("Darkest secret: ");
	this->index = index;
}

int	Contact::check(void)
{
	if (this->firstName.empty())
		return (1);
	return (0);
}
