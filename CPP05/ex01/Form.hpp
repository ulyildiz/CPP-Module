#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"
class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		bool				_signed;
		int					_gradeToSign;
		int					_gradeToExecute;
	public:
		Form(void);
		Form(const std::string& name, int gradeToSign, int gradeToExecute);
		Form(const Form& coppied);
		~Form(void);

		const std::string&	getName(void) const;
		const bool&			getSigned(void) const;
		const int&			getGradeToSign(void) const;
		const int&			getGradeToExecute(void) const;

		void				beSigned(const Bureaucrat& bureaucrat);

		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class FormAlreadySignedException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class NoFormException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

		Form& operator=(const Form& other);
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif