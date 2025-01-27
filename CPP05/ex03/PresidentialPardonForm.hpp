#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm: public AForm {
	private:
		std::string	_target;
		static const int _gradeToSign = 25;
		static const int _gradeToExecute = 5;
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& coppied);
		~PresidentialPardonForm(void);

		const std::string&	getTarget(void) const;

		void	executeAction(void) const;

		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
};

#endif