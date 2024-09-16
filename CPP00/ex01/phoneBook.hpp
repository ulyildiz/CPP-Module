#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
	private:
		Contact contacts[8];

	public:
ü		int		contactIndex;
		void	addContact(void);
		void	displayAll(void);
		void	searchContact(void);
		void	PhoneBookExit(void);
};

#endif