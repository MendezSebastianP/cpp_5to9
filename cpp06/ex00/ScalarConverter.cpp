# include <iostream>
# include <cctype>
# include "ScalarConverter.hpp"
# define CONST_MSG "\033[1;32mDefault constructor ScalarConverter called\033[0m"
# define CONST_N_MSG "\033[1;32mParametizered constructor ScalarConverter called. \033[0m"
# define CPY_CONST_MSG "\033[1;32mCopy constructor ScalarConverter called\033[0m"
# define CPY_ASSIG_OP_MSG "Copy assignment operator called"
# define DEST_MSG "\033[1;31mDestructor ScalarConverter called\033[0m"
# define INVALID -1
# define CHAR 0
# define INT 1
# define FLOAT 2
# define DOUBLE 3

ScalarConverter::ScalarConverter( void )
{
	std::cout << CONST_MSG << std::endl;
}

ScalarConverter::~ScalarConverter( void )
{
	std::cout << DEST_MSG << " for Name: " << std::endl;
}

int	ScalarConverter::ischar( std::string input, size_t len_input )
{
	if( len_input == 1 && !(std::isdigit(static_cast<unsigned char>(input[0]))) )
		return 1;
	else if (len_input == 2 && (input[0] == '-' || input[0] == '+')
		&& !(std::isdigit(static_cast<unsigned char>(input[0]))))
		return 1;
	return 0;
}

int	ScalarConverter::isint( std::string input, size_t len_input )
{
	for (size_t i = 0; i < len_input; i++)
	{
		if( !(std::isdigit(static_cast<unsigned char>(input[i]))) )
			return 0;
	}
	return 1;
}

int	ScalarConverter::isfloat( std::string input, size_t len_input )
{
	int count_dot = 0;
	int count_f = 0;
	int	i = 0;

	if ((input[0] == '+' || input[0] == '-') && len_input > 1)
		i++;
	while (i < len_input)
	{
		if(!(std::isdigit(static_cast<unsigned char>(input[i])))
			||  !(input[i] == '.' || input[i] == 'f'))
			return 0;
		if (input[i] == '.')
			count_dot++;
		if (input[i] == 'f')
			count_f++;
		i++;
	}
	if (count_f == 1 && count_dot == 1)
		return 1;
	return 0;
}

int	ScalarConverter::isdouble( std::string input, size_t len_input )
{
	int count_dot = 0;
	int	i = 0;

	if ((input[0] == '+' || input[0] == '-') && len_input > 1)
		i++;
	while (i < len_input)
	{
		if(!(std::isdigit(static_cast<unsigned char>(input[i])))
			||  !(input[i] == '.'))
			return 0;
		if (input[i] == '.')
			count_dot++;
		i++;
	}
	if (count_dot == 1)
		return 1;
	return 0;
}

int ScalarConverter::find_type( std::string input )
{
	size_t f = input.find("f");
	size_t dot = input.find(".");
	size_t len_input = input.length();

	if (dot == std::string::npos)
	{
		if (ScalarConverter::ischar(input, len_input))
			return CHAR;
		else if (ScalarConverter::isint(input, len_input))
			return INT;
		else
			return INVALID;
	}	
	if (f != std::string::npos && ScalarConverter::isfloat(input, len_input))
		return FLOAT;
	else if (ScalarConverter::isdouble(input, len_input))
		return DOUBLE;
	return INVALID;
	
}
