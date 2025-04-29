# include <iostream>
#include <cstdlib>
# include <cctype>
# include <limits>
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
// yes, input .0 work as intended:)

ScalarConverter::ScalarConverter( void )
{
	std::cout << CONST_MSG << std::endl;
}

ScalarConverter::~ScalarConverter( void )
{
	std::cout << DEST_MSG << " for Name: " << std::endl;
}

ScalarConverter::ScalarConverter( ScalarConverter const &src )
{
	*this = src;
	std::cout << CPY_CONST_MSG << std::endl;
}

ScalarConverter & ScalarConverter::operator= (ScalarConverter const & rhs)
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

int isint( std::string input, size_t len_input )
{
	size_t	i = 0;

	if ((input[0] == '+' || input[0] == '-') && len_input > 1)
		i++;
	while (i < len_input)
	{
		if( !(std::isdigit(static_cast<unsigned char>(input[i]))) )
			return 0;
		i++;
	}
	return 1;
}

int isfloat( std::string input, size_t len_input )
{
	int count_dot = 0;
	int count_f = 0;
	size_t	i = 0;

	if ((input[0] == '+' || input[0] == '-') && len_input > 1)
		i++;
	while (i < len_input)
	{
		if(!(std::isdigit(static_cast<unsigned char>(input[i])))
			&&  !(input[i] == '.' || input[i] == 'f'))
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

int isdouble( std::string input, size_t len_input )
{
	int count_dot = 0;
	size_t	i = 0;

	if ((input[0] == '+' || input[0] == '-') && len_input > 1)
		i++;
	while (i < len_input)
	{
		if(!(std::isdigit(static_cast<unsigned char>(input[i])))
			&&  !(input[i] == '.'))
			return 0;
		if (input[i] == '.')
			count_dot++;
		i++;
	}
	if (count_dot == 1)
		return 1;
	return 0;
}

int find_type( std::string input )
{
	size_t f = input.find("f");
	size_t dot = input.find(".");
	size_t len_input = input.length();

	if (dot == std::string::npos)
	{
		if (ischar(input, len_input))
			return CHAR;
		else if (isint(input, len_input))
			return INT;
		else
			return INVALID;
	}	
	if (f != std::string::npos && isfloat(input, len_input))
		return FLOAT;
	else if (isdouble(input, len_input))
		return DOUBLE;
	return INVALID;
	
}

void convert_char( std::string input )
{
	std::cout << "char: '" << input << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(input[0]) << std::endl;
	std::cout << "double: " << static_cast<double>(input[0]) << std::endl;
}

void convert_int( std::string input )
{
	long longn = std::atol(input.c_str());
	if (longn < 0 || longn > 127)
		std::cout << "char: impossible" << std::endl;
	else
	{
		if (isprint(longn))
			std::cout << "char: '" << static_cast<char>(longn) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	if (longn < std::numeric_limits<int>::min() || longn > std::numeric_limits<int>::max())
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(longn) << std::endl;
	std::cout << "float: " << static_cast<float>(longn) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(longn) << ".0" << std::endl;
}

void convert_float( std::string input )
{
	float floatn = std::atof(input.c_str());
	if (floatn < 0 || floatn > 127)
		std::cout << "char: impossible" << std::endl;
	else
	{
		if (isprint(floatn))
			std::cout << "char: '" << static_cast<char>(floatn) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	if (floatn < std::numeric_limits<int>::min() || floatn > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(floatn) << std::endl;
	std::cout << "float: " << static_cast<float>(floatn) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(floatn) << std::endl;
}

void convert_double( std::string input )
{
	double doublen = std::atof(input.c_str());
	if (doublen < 0 || doublen > 127)
		std::cout << "char: impossible" << std::endl;
	else
	{
		if (isprint(doublen))
			std::cout << "char: '" << static_cast<char>(doublen) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	if (doublen < std::numeric_limits<int>::min() || doublen > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(doublen) << std::endl;
	std::cout << "float: " << static_cast<float>(doublen) << "f" <<std::endl;
	std::cout << "double: " << static_cast<double>(doublen) << std::endl;
}

void invalid( std::string input )
{
	if (input == "nan")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return ;
	}
	else if (input == "-inff" || input == "-inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return ;
	}
	else if (input == "+inff" || input == "+inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return ;
	}
	std::cout << "Invalid input: " << input << std::endl
	<< ". Valid argument examples: literal<\"a\">, int<\"1\">, float <\"1.0f\">, double <\"1.0\".>" 
	<< std::endl;
}

void ScalarConverter::convert( const std::string &input )
{
	int type = find_type(input);

	switch (type)
	{
	case CHAR:
		convert_char( input );
		break;
	case INT:
		convert_int( input );
		break;
	case FLOAT:
		convert_float( input );
		break;
	case DOUBLE:
		convert_double( input );
		break;
	case INVALID:
		invalid( input );
		break;
	}
}