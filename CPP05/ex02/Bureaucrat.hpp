#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream> 
# include "AForm.hpp"

class AForm;

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat& coppied);
		Bureaucrat(const std::string& name);
		Bureaucrat(const std::string& name, int grade);
		~Bureaucrat(void);

		static const int	_highestGrade = 1;
		static const int	_lowestGrade = 150;

		const std::string&	getName(void) const;
		const int&			getGrade(void) const;
		void				incrementGrade(void);
		void				decrementGrade(void);

		void				signForm(AForm* form) const;
		void				executeForm(const AForm* form) const;

		Bureaucrat&			operator=(const Bureaucrat& other);

		class GradeTooHighException: public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				const char* what() const throw();
		};

};

std::ostream&		operator<<(std::ostream& os, const Bureaucrat& b);

#endif