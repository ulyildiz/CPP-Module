#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm: public AForm {
	private:
		std::string	_target;;
		static const int _gradeToSign = 145;
		static const int _gradeToExecute = 137;
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& coppied);
		~ShrubberyCreationForm(void);

		const std::string&	getTarget(void) const;

		void	executeAction(void) const;

		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
};

#endif