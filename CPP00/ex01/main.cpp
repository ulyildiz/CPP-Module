#include <iostream>
#include "phoneBook.hpp"

int	main(int argc, char *argv[])
{
	std::string	input;
	phoneBook	phone_book;

	phone_book.contactIndex = 0;
	if (argc != 1)
		std::cout << argv[0] << " Can't take more than one argument." << std::endl;

	do {
		std::getline(std::cin, input);
		if (input == "ADD")
			phone_book.addContact();
		else if (input == "SEARCH")
			phone_book.searchContact();
		else if (input == "EXIT")
			phone_book.phoneBookExit();
		else
			std::cout << "Invalid command" << std::endl;
	} while (1);

	return (0);
}