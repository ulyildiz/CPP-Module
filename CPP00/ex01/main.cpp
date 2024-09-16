#include <iostream>
#include "PhoneBook.hpp"

int	main(int argc, char *argv[])
{
	std::string	input;
	PhoneBook	phone_book;

	phone_book.contactIndex = 0;
	if (argc != 1)
		std::cout << argv[0] << " Can't take more than one argument." << std::endl;

	do {
		if (!std::getline(std::cin, input))
			break ;
		if (input == "ADD")
			phone_book.addContact();
		else if (input == "SEARCH")
			phone_book.searchContact();
		else if (input == "EXIT")
			phone_book.PhoneBookExit();
		else
			std::cout << "Invalid command." << std::endl;
	} while (true);

	return (0);
}