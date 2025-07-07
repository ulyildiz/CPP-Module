#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <sstream>

class RPN
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
		RPN(std::istringstream &iss);
		~RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);

		void	doRPN();
};

#endif