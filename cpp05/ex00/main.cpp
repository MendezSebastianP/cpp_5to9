# include <iostream>
# include <cctype>
# include "Bureaucrat.hpp"

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
	Bureaucrat *sam;
	Bureaucrat *karen;
	Bureaucrat *jack;
	Bureaucrat *alex;
	Bureaucrat *xavier;

	sep(2, "CONSTRUCTOR");
	try
	{
		sam = new Bureaucrat("Sam", 67);
		karen = new Bureaucrat("Karen", 148);
		jack = new Bureaucrat("Jack", 3);
		alex = new Bureaucrat("Alex", -1); // fails and doesnt create it and neither the next one
		xavier = new Bureaucrat("Xavier", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	sep(2, "CHECK VALUES");
	std::cout << *sam;
	std::cout << *karen;
	std::cout << *jack;

	sep(2, "INCREMENT");
	std::cout << *karen;
	try { karen->decrementGrade(); }
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
	std::cout << *karen;
	try { karen->decrementGrade(); }
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
	std::cout << *karen;
	try { karen->decrementGrade(); }
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
	std::cout << *karen;
	try { karen->decrementGrade(); }
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
	std::cout << *karen;

	sep(2, "DECREMENT");
	std::cout << *jack;
	try { jack->incrementGrade(); }
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
	std::cout << *jack;
	try { jack->incrementGrade(); }
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
	std::cout << *jack;
	try { jack->incrementGrade(); }
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
	std::cout << *jack;
	try { jack->incrementGrade(); }
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
	std::cout << *jack;

	sep(2, "DESTRUCTOR");
	delete jack;
	delete karen;
	delete sam;
	return 0;
}