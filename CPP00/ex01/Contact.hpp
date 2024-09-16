#pragma once

# include <iostream>

class Contact {
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
		void	displayExtented(void);
		void	displayLimited(void);
};
