#ifndef INTERN_HPP
# define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	private:
		static const int _formCount = 3; 
		struct FormType {
			std::string	formName;
			AForm*		(*formCreation)(const std::string& target);
		} _formTypes[3] = {
			{"shrubbery creation", &ShrubberyCreationForm::createForm},
			{"robotomy request", &RobotomyRequestForm::createForm},
			{"presidential pardon", &PresidentialPardonForm::createForm}
		};
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