#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool				_signed;
		int					_gradeToSign;
		int					_gradeToExecute;
	public:
		AForm(void);
		AForm(const std::string& name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& coppied);
		virtual ~AForm(void);

		const std::string&	getName(void) const;
		const bool&			getSigned(void) const;
		const int&			getGradeToSign(void) const;
		const int&			getGradeToExecute(void) const;

		void				beSigned(const Bureaucrat& bureaucrat);
		void				execute(const Bureaucrat& executor) const;
		virtual void		executeAction(void) const = 0;				

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
		class FormNotSignedException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class NoFormException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

		AForm& operator=(const AForm& other);
};

std::ostream& operator<<(std::ostream& out, const AForm& Aform);

#endif