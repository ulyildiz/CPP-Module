#ifndef INTERN_HPP
# define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class ShurbberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

class Intern {
	private:
		typedef struct _FormType {
			std::string name;
			AForm *obj;
		} t_formType;
		t_formType static const formTypes[3];
	public:
		Intern(void);
		Intern(const Intern& coppied);
		~Intern(void);
	
		Intern& operator=(const Intern& other);
	
		AForm*	makeForm(const std::string& formName, const std::string& target) const;

		class FormNotFoundException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif