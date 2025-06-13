#include "Span.hpp"

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

int main( void )
{
	sep(2, "MAIN TESTS");
	Span sp(5);
	try 
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
    	std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }


	sep(2, "SHORT TESTS");
	Span t0(1); 
	try 
	{
		std::cout << t0.shortestSpan() << std::endl;
		std::cout << t0.longestSpan() << std::endl;
	}
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }

	sep(2, "LONG TESTS");
	Span t1(100);
	Span t2(10000);
	Span t3(10000); 

	try {t1.add_range(10, 1);}
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
	try {t2.add_range(0, 10);}
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
	std::cout << "Shortest span: " << (t2.shortestSpan()) << std::endl;
	std::cout << "longest span: " << (t2.longestSpan()) << std::endl;
	try {t3.add_range(0, 10000);}
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
	std::cout << "Shortest span: " << (t3.shortestSpan()) << std::endl;
	std::cout << "longest span: " << (t3.longestSpan()) << std::endl;
	

	return 0;
}


