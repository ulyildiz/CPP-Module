#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern {
	private:
		
	public:
		Intern(void);
		Intern(const Intern& coppied);
		~Intern(void);

		Intern& operator=(const Intern& other);

		AForm*	makeForm(const std::string& formName, const std::string& target);
};

#endif