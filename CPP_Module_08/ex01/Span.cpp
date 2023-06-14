#include "Span.hpp"

Span::Span(void): N(0), max(0)
{
}

Span::Span(int nb) : N(0), max(nb)
{
}

Span::Span(const Span &src)
{
    *this = src;
}

Span &Span::operator=(const Span &src)
{
    this->~Span();
    this->max = src.max;
    this->N = src.N;
    return (*this);
}
Span::~Span()
{
}

void Span::addNumber(int nb)
{
    if (this->N.size() == (unsigned int)this->max)
       throw Span::tooException();
    N.push_back(nb);
}

int Span::getN(int nb)
{
    return (this->N[nb]);
}

int	Span::shortestSpan( void )
{
	std::vector<unsigned int>			tmp = N;
	int							result = -1;
	std::vector<unsigned int>::iterator	it;

	if (N.size() <= 1)
		throw Span::tooException();
	sort(tmp.begin(), tmp.end());
	result = *(tmp.begin() + 1) - *tmp.begin();
	if (this->N.size() == 2)
		return result;
	for (it = tmp.begin() + 1; it != tmp.end() - 1 && result != 0; it++)
	{
		if (*(it + 1) - ((unsigned int)*it < (unsigned int)result))
			result = *(it + 1) - *it;
	}
	return result;
}

int	Span::longestSpan( void )
{
	std::vector<unsigned int>	tmp = N;

	if (N.size() <= 1)
		throw Span::tooException();
	sort(tmp.begin(), tmp.end());
	return *(tmp.end() - 1) - *tmp.begin();
}

void	Span::addByIteratorRange( std::vector<int>::iterator begin,
		std::vector<int>::iterator end)
{
	std::vector<int>	tmp(begin, end);

	if (tmp.size() > (unsigned int)this->max)
		throw std::out_of_range("Cannot add any more numbers");
	copy(tmp.begin(), tmp.end(), std::back_inserter(this->N));
}