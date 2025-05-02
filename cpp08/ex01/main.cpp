#include "Span.hpp"

int main( void )
{
	Span *t1 = new Span();
	// int data[101];
	for (size_t i = 0; i < 10000000; i++)
	{
		t1->addNumber(i);
	}
	try { std::cout << "Shortest span: " << (t1->shortestSpan()) << std::endl; }
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
	try { std::cout << "Shortest span: " << (t1->longestSpan()) << std::endl; }
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
	delete t1;
	return 0;
}