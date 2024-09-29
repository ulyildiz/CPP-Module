#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain constructor." << std::endl;
}

Brain::Brain(const Brain& coppied)
{
	std::cout << "Brain copy constructor." << std::endl;
	*this = coppied;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor." << std::endl;
}

void	Brain::setIdea(const std::string& idea, int index)
{
	if (index > 0 && index < 101)
		this->ideas[index - 1] = idea;
	else
		std::cout << "Index should be between 0-101." << std::endl;
}

std::string Brain::getIdea(int index)
{
	if (index > 0 && index < 101) // 0 ve 100 bir değişken yap
		return (this->ideas[index - 1]);
	std::cout << "There is no valid index." << std::endl;
	return (NULL);
}

Brain&	Brain::operator=(const Brain& other)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i]; // if we can use private var like this why get/set?
	return (*this);
}