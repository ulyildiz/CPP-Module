#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>

class contact {
	private:
		int			index;
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;
	public:
		int		check(void);
		void	fillContact(int index);
		void	displayContact(void);
};

class phoneBook {
	private:
		contact contacts[8];

	public:
		int		contactIndex;
		void	addContact(void);
		void	displayAll(void);
		void	searchContact(void); // const because it doesn't modify the object
		void	phoneBookExit(void);
};

#endif