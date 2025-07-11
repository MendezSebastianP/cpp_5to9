# include <iostream>
# include <cctype>
# include "Span.hpp"
# define CONST_MSG "\033[1;32mDefault constructor Span called\033[0m"
# define CONST_N_MSG "\033[1;32mParametizered constructor Span called.\033[0m"
# define CPY_CONST_MSG "\033[1;32mCopy constructor Span called\033[0m"
# define CPY_ASSIG_OP_MSG "Copy assignment operator called"
# define DEST_MSG "\033[1;31mDestructor Span called\033[0m"

Span::Span( void )
	: samenumber(false), N_max_(N_MAX), count_n_(0)
{
	std::cout << CONST_MSG << std::endl;
}

Span::Span( unsigned int numb )
	: samenumber(false), N_max_(numb), count_n_(0)
{
	std::cout << CONST_N_MSG << std::endl;
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
	if (static_cast<int>(span_.size()) > N_max_)
		throw std::range_error("Error: Too much numbers. Try with N < Max N");
	if (span_.find(numb) != span_.end())
		samenumber = true;
	span_.insert(numb);
	count_n_++;
}

int Span::shortestSpan( void ) const
{
	int  dif, shortest = -1;
	std::set<int>::const_iterator it1 = span_.begin();
	std::set<int>::const_iterator it2 = span_.begin();
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
	while (it2 != span_.end())
	{
		// std::cout << (static_cast<const unsigned int>(*i)) <<" number\n";
		// std::cout << shortest <<" shortest\n it1: " << *it1 << ". it2: " << *it2 << "\n";
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
		// std::cout << "next step\n it1: " << *it1 << ". it2: " << *it2 << "\n";
	}
	// std::cout << shortest <<" shortest\n";
	return shortest;
}

void Span::add_range(int min, int max)
{
	if (max - min > N_max_)
		throw std::range_error("\033[1;31mError\033[0m: Too much numbers. Try with N < Max N");
	if (min > max)
		throw std::range_error("\033[1;31mError\033[0m: Not valid range");
	for (int i = min; i < max; i++)
	{
		span_.insert(i);
		count_n_++;
	}
}

int Span::longestSpan( void ) const
{
	int  longuest = -1;
	std::set<int>::const_iterator it1 = span_.begin();
	std::set<int>::const_iterator it2 = span_.begin();
	if (span_.size() > 1)
	{
		std::advance(it2, span_.size() - 1);
		longuest = std::abs(*it2 - *it1);
	}
	else
	{
		throw std::range_error("\033[1;31mError\033[0m: You need at least 2 numbers in your class in order to use this function.");
	}
	return longuest;
}
