#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <vector>

template <typename T, typename C = std::vector<T> >
class MutantStack: public std::stack<T, C> {
	public:
		MutantStack(): std::stack<T, C>() {}
		MutantStack(const MutantStack &copied): std::stack<T, C>(copied) {}
		~MutantStack() { this->c.clear(); }
		MutantStack &operator=(const MutantStack &other)
		{
			if (this == &other)
				return *this;
			this->c = other.c;
			return *this;
		}

		typedef typename MutantStack<T, C>::container_type::iterator iterator;
		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }

		typedef typename MutantStack<T, C>::container_type::const_iterator const_iterator;
		const_iterator begin() const { return this->c.begin(); }
		const_iterator end() const { return this->c.end(); }

		typedef typename MutantStack<T, C>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin() { return this->c.rbegin(); }
		reverse_iterator rend() { return this->c.rend(); }

		typedef typename MutantStack<T, C>::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator rbegin() const { return this->c.rbegin(); }
		const_reverse_iterator rend() const { return this->c.rend(); }

};

#endif