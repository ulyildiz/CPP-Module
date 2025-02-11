#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack: public std::stack<T> {
	private:

	public:
		MutantStack(): std::stack<T, std::vector<int> >() {}
		MutantStack(const MutantStack &copied): std::stack<T>(copied) {}
		~MutantStack() { this->c.clear(); }
		MutantStack &operator=(const MutantStack &other)
		{
			if (this == &other)
				return *this;
			this->c = other.c;
			return *this;
		}

		typedef typename MutantStack<T>::container_type::iterator iterator;
		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }

		typedef typename MutantStack<T>::container_type::const_iterator const_iterator;
		const_iterator begin() const { return this->c.begin(); }
		const_iterator end() const { return this->c.end(); }

		typedef typename MutantStack<T>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin() { return this->c.rbegin(); }
		reverse_iterator rend() { return this->c.rend(); }

		typedef typename MutantStack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator rbegin() const { return this->c.rbegin(); }
		const_reverse_iterator rend() const { return this->c.rend(); }

		
};

#endif