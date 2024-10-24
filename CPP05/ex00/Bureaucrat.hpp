#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream> 

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;
		static const int	_highestGrade = 1;
		static const int	_lowestGrade = 150;

	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat& coppied);
		Bureaucrat(std::string name);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat(void);
		
		const std::string&	getName(void) const;
		int					getGrade(void);

		int					randomGrade(void);
		void				incrementGrade(void);
		void				decrementGrade(void);

		Bureaucrat&			operator=(const Bureaucrat& other);
};

std::ostream&		operator<<(std::ostream& os, Bureaucrat& const b);

#endif