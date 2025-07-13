#include "Span.hpp"

Span::Span(unsigned int n) : _n(n)
{
}

Span::Span(const Span &src)
{
	*this = src;
}

Span::~Span()
{
}

Span &Span::operator=(const Span &rhs)
{
	if (this != &rhs)
	{
		_n = rhs._n;
		_v = rhs._v;
	}
	return (*this);
}

void Span::addNumber(int n)
{
	if (_v.size() >= _n)
		throw std::out_of_range("Span is full");
	_v.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_v.size() + std::distance(begin, end) > _n)
		throw std::out_of_range("Span will be full");
	_v.insert(_v.end(), begin, end);
}

int Span::shortestSpan()
{
	if (_v.size() <= 1)
		throw std::logic_error("Not enough numbers to find a span");

	std::vector<int> sorted = _v;
	std::sort(sorted.begin(), sorted.end());

	int min_span = sorted[1] - sorted[0];
	for (size_t i = 2; i < sorted.size(); i++)
	{
		if (sorted[i] - sorted[i - 1] < min_span)
			min_span = sorted[i] - sorted[i - 1];
	}
	return (min_span);
}

int Span::longestSpan()
{
	if (_v.size() <= 1)
		throw std::logic_error("Not enough numbers to find a span");

	return (*std::max_element(_v.begin(), _v.end()) - *std::min_element(_v.begin(), _v.end()));
}