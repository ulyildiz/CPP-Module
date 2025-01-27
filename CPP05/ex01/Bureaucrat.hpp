#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream> 
# include "Form.hpp"

class Form;

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;
		static const int	_highestGrade = 1;
		static const int	_lowestGrade = 150;

	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat& coppied);
		Bureaucrat(const std::string& name);
		Bureaucrat(const std::string& name, int grade);
		~Bureaucrat(void);

		const std::string&	getName(void) const;
		const int&			getGrade(void) const;
/* 		const int&			getHighestGrade(void) const;
		const int&			getLowestGrade(void) const; */
		void				incrementGrade(void);
		void				decrementGrade(void);

		void				signForm(Form& form) const;

		Bureaucrat&			operator=(const Bureaucrat& other);

		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

};

std::ostream&		operator<<(std::ostream& os, const Bureaucrat& b);

#endif