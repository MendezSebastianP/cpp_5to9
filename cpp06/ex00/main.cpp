# include <iostream>
# include <cctype>
# include "ScalarConverter.hpp"
# define ARG_ERR "Please, put only one argument, it could be a <int>, sigle <char>, <float> or <double>"

void sep( size_t n, std::string msg)
{
	std::cout << std::endl;
	for (size_t i = 0; i < n; i++)
		std::cout << "#########################################################################" << std::endl;
	std::cout << "                            " << msg << std::endl;
	for (size_t i = 0; i < n; i++)
		std::cout << "#########################################################################" << std::endl;
	std::cout << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << ARG_ERR << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
}