# include <iostream>
# include <cctype>
# include <ctime>
# include <cstdlib>
# include <cctype>
# include "Base.hpp"
# include "ABC.hpp"
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

int	main(void)
{
	std::srand(static_cast<unsigned>(std::time(NULL)));
	Base *test = generate();
	Base *test2 = NULL;

	identify(test);
	identify(*test);

	identify(test2);
	identify(*test2);
	return 0;
}