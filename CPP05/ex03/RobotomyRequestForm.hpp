#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm: public AForm {
	private:
		std::string	_target;
		static const int _gradeToSign = 72;
		static const int _gradeToExecute = 45;
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& coppied);
		~RobotomyRequestForm(void);

		const std::string&	getTarget(void) const;
		
		void			executeAction(void) const;
		static AForm*	createForm(const std::string& target);

		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
};

#endif