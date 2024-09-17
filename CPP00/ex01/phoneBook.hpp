#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
	private:
		Contact _contacts[8];

	public:
		int		contactIndex;
		bool	addContact(void);
		void	displayAll(void);
		bool	searchContact(void);
};

#endif