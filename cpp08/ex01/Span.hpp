#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <cctype>
# include <set>
#include <iterator>
#include <stdlib.h>
# define N_MAX 10000000

class Span {
    public:
	// canonic
	Span( void );
	Span( std::string Name );
	~Span( void );
	Span( Span const &src);
	Span & operator =( Span const & rhs);

	void addNumber(int numb );
	int shortestSpan( void ) const;
	int longestSpan( void ) const;

	private:
	std::set<int> span_;
	bool samenumber;

};


#endif