# include <iostream>
# include <cctype>
# include "Span.hpp"
# define CONST_MSG "\033[1;32mDefault constructor Span called\033[0m"
# define CPY_CONST_MSG "\033[1;32mCopy constructor Span called\033[0m"
# define CPY_ASSIG_OP_MSG "Copy assignment operator called"
# define DEST_MSG "\033[1;31mDestructor Span called\033[0m"

Span::Span( void )
	: samenumber(false)
{
	std::cout << CONST_MSG << std::endl;
}

Span::~Span( void )
{
	std::cout << DEST_MSG << " for Span" << std::endl;
}

Span::Span( Span const &src )
{
	(void)src;
	std::cout << CPY_CONST_MSG << std::endl;
}

Span & Span::operator= (Span const & rhs)
{
	std::cout << CPY_ASSIG_OP_MSG << std::endl;
	(void)rhs;
	return *this;
}

void Span::addNumber( int numb )
{
	if (span_.find(numb) != span_.end())
		samenumber = true;
	span_.insert(numb);
}

int Span::shortestSpan( void ) const
{
	int  dif, shortest = -1;
	std::set<int>::const_iterator it1 = span_.begin();
	std::set<int>::const_iterator it2 = span_.begin();
	if (span_.size() > N_MAX)
		throw std::range_error("Error: Too much numbers. Try with N < Max N");
	if (span_.size() > 1)
	{
		std::advance(it2, 1);
		shortest = std::abs(*it2 - *it1);
	}
	else
	{
		throw std::range_error("Error: You need at least 2 numbers in your class in order to use this function.");
	}
	if (samenumber)
		return 0;
	for (std::set<int>::iterator i = span_.begin(); i != span_.end(); i++)
	{
		if (it2 != span_.end())
		{
			dif = std::abs(*it2 - *it1);
			if (dif < shortest)
				shortest = dif;
		}
		else
			break;
		std::advance(it1, 1);
		std::advance(it2, 1);
	}
	return shortest;
}

int Span::longestSpan( void ) const
{
	int  dif, longuest = -1;
	std::set<int>::const_iterator it1 = span_.begin();
	std::set<int>::const_iterator it2 = span_.begin();
	if (span_.size() > N_MAX)
		throw std::range_error("Error: Too much numbers. Try with N < Max N");
	if (span_.size() > 1)
	{
		std::advance(it2, 1);
		longuest = std::abs(*it2 - *it1);
	}
	else
	{
		throw std::range_error("You need at least 2 numbers in your class in order to use this function.");
	}
	for (std::set<int>::iterator i = span_.begin(); i != span_.end(); i++)
	{
		if (it2 != span_.end())
		{
			dif = std::abs(*it2 - *it1);
			if (dif > longuest)
				longuest = dif;
		}
		else
			break;
		std::advance(it1, 1);
		std::advance(it2, 1);
	}
	return longuest;
}
