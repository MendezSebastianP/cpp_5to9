# include <iostream>
# include <cctype>
# include "Bureaucrat.hpp"
# include "Form.hpp"

void sep( size_t n, std::string msg)
{
	if (n > 1)
		std::cout << std::endl;
	for (size_t i = 0; i < n; i++)
		std::cout << "#########################################################################" << std::endl;
	if (msg.length())
	{
		std::cout << "                            " << msg << std::endl;
		for (size_t i = 0; i < n; i++)
		std::cout << "#########################################################################" << std::endl;
	}
	if (n > 1)
		std::cout << std::endl;
	}

int	main(void)
{
	Bureaucrat *sam;
	Bureaucrat *karen;
	Bureaucrat *xavier;

	Form *more_taxes = new Form("Our bureaucrats need bigger cars, More Taxes!");
	Form *raice_salaries = new Form("Let's raise the salaries to everyone :D");
	
	sep(2, "CONSTRUCTOR");
	try
	{
		sam = new Bureaucrat("Sam", 49);
		karen = new Bureaucrat("Karen", 148);
		xavier = new Bureaucrat("Xavier", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	sep(2, "CHECK BUREAUCRATS");
	std::cout << *sam;
	std::cout << *karen;

	sep(2, "CHECK FORMS");
	std::cout << *more_taxes;
	sep(1, "");
	std::cout << *raice_salaries;

	sep(2, "SIGN FORMS");
	try { sam->signForm(*more_taxes); }
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
	try { karen->signForm(*raice_salaries); }
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }

	sep(2, "CHECK FORMS (AGAIN...)");
	std::cout << *more_taxes;
	sep(1, "");
	std::cout << *raice_salaries;

	sep(2, "DESTRUCTOR");
	delete raice_salaries;
	delete more_taxes;
	delete karen;
	delete sam;
	return 0;
}