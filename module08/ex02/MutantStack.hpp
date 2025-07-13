#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack() {}
		MutantStack(const MutantStack &src) { *this = src; }
		~MutantStack() {}

		MutantStack &operator=(const MutantStack &rhs)
		{
			if (this != &rhs)
				this->c = rhs.c;
			return (*this);
		}

		typedef typename Container::iterator iterator;

		iterator begin() { return (this->c.begin()); }
		iterator end() { return (this->c.end()); }
};

#endif