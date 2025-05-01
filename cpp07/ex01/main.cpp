# include <iostream>
# include <cctype>
# include "Iter.hpp"
# include "Data.hpp"

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
	// ints
    int nums[] = { 0, 1, 2, 3, 4 };
    std::cout << "Original ints: ";
    iter(nums, 5, printElem<int>);
    std::cout << "\nAfter increment: ";
    iter(nums, 5, increment);
    iter(nums, 5, printElem<int>);
    std::cout << "\n\n";

	// strings
    std::string words[] = { "hello", "world", "iter", "template" };
    std::cout << "Original strings: ";
    iter(words, 4, printElem<std::string>);
    std::cout << "\nAfter shout: ";
    iter(words, 4, shout);
    iter(words, 4, printElem<std::string>);
    std::cout << "\n\n";


	// class and function member
	Data *data = new Data();
	std::cout << "Original strings: ";
	iter(data->data, data->sizen, data, &Data::printdata<int>);
	std::cout << "\nAfter times2 class member function: ";
	iter(data->data, data->sizen, data, &Data::times2);
	iter(data->data, data->sizen, data, &Data::printdata<int>);
	std::cout << "\n\n";

	delete data;
    return 0;
}
