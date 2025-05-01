# include <iostream>
#include <cstdlib>
# include <cctype>
# include <limits>
# include "Data.hpp"
# define CONST_MSG "\033[1;32mDefault constructor Data called\033[0m"
# define CONST_N_MSG "\033[1;32mParametizered constructor Data called. \033[0m"
# define CPY_CONST_MSG "\033[1;32mCopy constructor Data called\033[0m"
# define CPY_ASSIG_OP_MSG "Copy assignment operator called"
# define DEST_MSG "\033[1;31mDestructor Data called\033[0m"

Data::Data( void )
{
	int ex_data[] = {42, 21, 442, 221, 4442, 2221, 44442, 22221, 444442, 222221};

	for (size_t i = 0; i < 10; i++)
	{
		data[i] = ex_data[i];
	}
	sizen = 10;
	std::cout << CONST_MSG << std::endl;
	
}

Data::~Data( void )
{
	std::cout << DEST_MSG << " for Data." << std::endl;
}

Data::Data( Data const &src )
{
	for (size_t i = 0; i < 10; i++)
	{
		data[i] = src.data[i];
	}
	*this = src;
	sizen = 10;
	std::cout << CPY_CONST_MSG << std::endl;
}

Data & Data::operator= (Data const & rhs)
{
	std::cout << CPY_ASSIG_OP_MSG << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		data[i] = rhs.data[i];
	}
	sizen = 10;
	return *this;
}
template void Data::printdata<int>(int const&);

template< typename T>
void Data::printdata(const T &x)
{
		std::cout << x << ' ';
}

void Data::times2( int &num )
{
		num *= 2;
}
