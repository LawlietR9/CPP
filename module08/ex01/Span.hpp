#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <stdexcept>

class Span
{
	private:
		std::vector<int> _v;
		unsigned int _n;

	public:
		Span(unsigned int n);
		Span(const Span &src);
		~Span();

		Span &operator=(const Span &rhs);

		void addNumber(int n);
		void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan();
		int longestSpan();
};

#endif