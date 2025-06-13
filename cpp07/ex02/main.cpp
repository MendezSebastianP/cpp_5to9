# include <iostream>
# include <cctype>
# include <stdlib.h> 
# include "Array.hpp"
#define MAX_VAL 750

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
	// init
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
	// filling with random numbers
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    // testing  copy and assignment operator
	Array<int> tmp = numbers;
	Array<int> test(tmp);
	// checking if there is any difference between the array and the int array
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didnt save the same value!!" << std::endl;
            return 1;
        }
    }
	// test invalid index
    try { numbers[-2] = 0; }
    catch(const std::exception& e)
    { std::cerr << e.what() << '\n'; }

	// test right index (no error)
    try { numbers[MAX_VAL] = 0; }
    catch(const std::exception& e)
    { std::cerr << e.what() << '\n'; }

    delete [] mirror;//
    return 0;
}
