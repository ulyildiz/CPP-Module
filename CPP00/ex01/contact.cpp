#include "PhoneBook.hpp"
#include <iomanip>

bool	checkForPrint(std::string input)
{
	size_t	inputLen;

	if (input.empty())
		return (false);
	inputLen = input.length();
	for (size_t i = 0; i < inputLen; i++)
	{
        if (!std::isprint(input[i]))
			return (false);
	}
	return (true);
}

std::string	get_input(std::string message)
{
	std::string	input;

	do {
		std::cout << message;
		if (!std::getline(std::cin, input))
			return ("");
		if (input.empty() || !checkForPrint(input))
		{
			std::cout << "Please enter a valid input." << std::endl;
			input.clear();
		}
	} while (input.empty());

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
	std::cout << std::setw(10) << this->_index << "|";
	std::cout << std::setw(10) << truncateAndFix(this->_firstName) << "|";
	std::cout << std::setw(10) << truncateAndFix(this->_lastName) << "|";
	std::cout << std::setw(10) << truncateAndFix(this->_nickname) << std::endl;
}

void	Contact::displayExtented(void)
{
	std::cout << "First name: " << this->_firstName << std::endl;
	std::cout << "Last name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << this->_darkestSecret << std::endl;
}

bool	Contact::fillContact(int index)
{
	if ((this->_firstName = get_input("First name: ")).empty())
		return (false);
	if ((this->_lastName = get_input("Last name: ")).empty())
		return (false);
	if ((this->_nickname = get_input("Nickname: ")).empty())
		return (false);
	if ((this->_phoneNumber = get_input("Phone number: ")).empty())
		return (false);
	if ((this->_darkestSecret = get_input("Darkest secret: ")).empty())
		return (false);
	this->_index = index;
	return (true);
}

int	Contact::check(void)
{
	if (this->_firstName.empty())
		return (1);
	return (0);
}
