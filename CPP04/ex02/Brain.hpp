#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	private:
		std::string	ideas[100];

	public:
		Brain(void);
		Brain(const Brain& coppied);
		~Brain(void);

		void		setIdea(const std::string& idea, int index);
		std::string	getIdea(int index);
		Brain&	operator=(const Brain& other);
};



#endif