#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <sstream>

class Operations
{
	private:
		std::stack<int> num;
		std::stack<char> op;

		bool	isOperator(const std::string &s) const;
		bool	isNumber(const std::string &s) const;
		
		void    add();
		void    sub();
		void    mul();
		void    div();
	
	public:
		Operations();
		Operations(std::istringstream &iss);
		~Operations();
		Operations(const Operations &other);
		Operations &operator=(const Operations &other);

		void	doOperations();
};

#endif