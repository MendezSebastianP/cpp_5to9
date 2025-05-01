# include <iostream>
#include <cstdlib>
# include <cctype>
# include <limits>
# include "Serializer.h"
# define CONST_MSG "\033[1;32mDefault constructor Serializer called\033[0m"
# define CONST_N_MSG "\033[1;32mParametizered constructor Serializer called. \033[0m"
# define CPY_CONST_MSG "\033[1;32mCopy constructor Serializer called\033[0m"
# define CPY_ASSIG_OP_MSG "Copy assignment operator called"
# define DEST_MSG "\033[1;31mDestructor Serializer called\033[0m"



Serializer::Serializer( void )
{
	std::cout << CONST_MSG << std::endl;
}

Serializer::~Serializer( void )
{
	std::cout << DEST_MSG << " for Name: " << std::endl;
}

Serializer::Serializer( Serializer const &src )
{
	*this = src;
	std::cout << CPY_CONST_MSG << std::endl;
}

Serializer & Serializer::operator= (Serializer const & rhs)
{
	std::cout << CPY_ASSIG_OP_MSG << std::endl;
	(void)rhs;
	return *this;
}

int ischar( std::string input, size_t len_input )
{
	if( len_input == 1 && !(std::isdigit(static_cast<unsigned char>(input[0]))) )
		return 1;
	return 0;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}


