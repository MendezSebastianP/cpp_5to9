# include <iostream>
# include <cctype>
# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

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
	
	sep(2, "CONSTRUCTOR");
	AForm *tree_dictator = new ShrubberyCreationForm("Tree for dictator");
	AForm *tree_legit = new ShrubberyCreationForm("legit tree to save the world");

	AForm *robot_inocent = new RobotomyRequestForm("a grandma");
	AForm *robot_politician = new RobotomyRequestForm("the mayor");

	AForm *presidents_brother = new PresidentialPardonForm("Dictators drunk big brother...");
	AForm *national_heroe = new PresidentialPardonForm("A hero");
	
	try
	{
		sam = new Bureaucrat("Sam", 4);
		karen = new Bureaucrat("Karen", 145);
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
	std::cout << *tree_dictator;
	std::cout << *tree_legit;
	sep(1, "");
	std::cout << *robot_inocent;
	std::cout << *robot_politician;
	sep(1, "");
	std::cout << *presidents_brother;
	std::cout << *national_heroe;


	sep(2, "SIGN FORMS");
	try { sam->signAForm(*tree_dictator); }
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
	try { karen->signAForm(*tree_legit); }
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
	sep(1, "");
	try { sam->signAForm(*robot_inocent); }
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
	try { karen->signAForm(*robot_politician); }
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
	sep(1, "");
	try { sam->signAForm(*presidents_brother); }
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
	try { karen->signAForm(*national_heroe); }
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }

	sep(2, "CHECK AFormS (AGAIN...)");
	std::cout << *tree_dictator;
	std::cout << *tree_legit;
	sep(1, "");
	std::cout << *robot_inocent;
	std::cout << *robot_politician;
	sep(1, "");
	std::cout << *presidents_brother;
	std::cout << *national_heroe;


	sep(2, "EXECUTE FORMS");
	try { sam->executeForm(*tree_dictator); }
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
	try { karen->executeForm(*tree_legit); }
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
	sep(1, "");
	try { sam->executeForm(*robot_inocent); }
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
	try { karen->executeForm(*robot_politician); }
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
	sep(1, "");
	try { sam->executeForm(*presidents_brother); }
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
	try { karen->executeForm(*national_heroe); }
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }


	sep(2, "DESTRUCTOR");
	delete national_heroe;
	delete presidents_brother;
	delete robot_inocent;
	delete robot_politician;
	delete tree_legit;
	delete tree_dictator;
	delete karen;
	delete sam;
	return 0;
}