# include <iostream>
# include <cctype>
# include "Fun.hpp"

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

int main()
{
    int a = 2;
    int b = 3;

    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << '\n';
    std::cout << "min(a, b) = " << ::min(a, b) << '\n';
    std::cout << "max(a, b) = " << ::max(a, b) << '\n';

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << '\n';
    std::cout << "min(c, d) = " << ::min(c, d) << '\n';
    std::cout << "max(c, d) = " << ::max(c, d) << '\n';

    return 0;
}
