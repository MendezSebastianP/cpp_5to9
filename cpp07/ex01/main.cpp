# include <iostream>
# include <cctype>
# include "Iter.hpp"

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

template< typename T>
void    printElem(const T &x)
{
    std::cout << x << ' ';
}

template< typename T>
void    printConst(const T &x)
{
    std::cout << x << ' ';
}

void    increment(int &x)
{
    ++x;
}

void    shout(std::string &s)
{
    s += "!";
}

int main()
{
	// int
    int nums[] = { 0, 1, 2, 3, 4 };
    std::cout << "Original ints: ";
    iter(nums, 5, printElem<int>);
    std::cout << "\nAfter increment: ";
    iter(nums, 5, increment);
    iter(nums, 5, printElem<int>);
    std::cout << "\n\n";

	// int const
    const int nums_c[] = { 0, 1, 2, 3, 4 };
	const int len = 5;
    std::cout << "Original ints: ";
    iter(nums_c, len, printConst<int>);
    std::cout << "\n\n";

	// strings
    std::string words[] = { "hello", "world", "iter", "template" };
    std::cout << "Original strings: ";
    iter(words, 4, printElem<std::string>);
    std::cout << "\nAfter shout: ";
    iter(words, 4, shout);
    iter(words, 4, printElem<std::string>);
    std::cout << "\n\n";

    return 0;
}
