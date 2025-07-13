#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <sstream>

class RPN
{
	private:
		std::stack<int>	expressions;

		bool	isOperator(const std::string &s) const throw();
		bool	isNumber(const std::string &s) const throw();

		void    add();
		void    sub();
		void    mul();
		void    div();

		template<typename T>
		void reverseStack(std::stack<T>& s)
		{
			std::stack<T> temp;
			while (!s.empty())
			{
				temp.push(s.top());
				s.pop();
			}
			s = temp;
		}
	
	public:
		RPN();
		~RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);

		void	doRPN(std::stringstream &iss);
		bool	isValidExpression(std::stringstream &iss) const throw();
};

#endif