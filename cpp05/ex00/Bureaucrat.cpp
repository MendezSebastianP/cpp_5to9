# include <iostream>
# include <cctype>
# include "Bureaucrat.hpp"
# define CONST_MSG "\033[1;32mDefault constructor Bureaucrat called\033[0m"
# define CONST_N_MSG "\033[1;32mParametizered constructor Bureaucrat called, name: \033[0m"
# define CPY_CONST_MSG "\033[1;32mCopy constructor Bureaucrat called\033[0m"
# define CPY_ASSIG_OP_MSG "Copy assignment operator called"
# define DEST_MSG "\033[1;31mDestructor Bureaucrat called\033[0m"

Bureaucrat::Bureaucrat( void )
	: Name_("Empty")
{
	std::cout << CONST_MSG << std::endl;
}

Bureaucrat::Bureaucrat( std::string Name )
	: Name_(Name)
{
	std::cout << CONST_N_MSG << Name << std::endl;
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << DEST_MSG << " for Name: " << Name_ << std::endl;
}

Bureaucrat::Bureaucrat( Bureaucrat const &src )
	: Name_(src.Name_)
{
	std::cout << CPY_CONST_MSG << std::endl;
	this->grade_ = src.grade_;
}

Bureaucrat & Bureaucrat::operator= (Bureaucrat const & rhs)
{
	std::cout << CPY_ASSIG_OP_MSG << std::endl;
	this->grade_ = rhs.grade_;
	return *this;
}


