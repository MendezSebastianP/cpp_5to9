# include <iostream>
#include <cstdlib>
# include <cctype>
# include <limits>
# include <ctime>
# include "Base.hpp"
# include "ABC.hpp"
# define DEST_MSG "\033[1;31mDestructor Base called\033[0m"


Base::~Base( void )
{
	std::cout << DEST_MSG << std::endl;
}

Base *generate(void)
{
	int random = 0;

	Base *base = NULL;
	random = std::rand() % 3 + 1;
	switch (random)
	{
		case 1:
			base = new A;
			std::cout << "A chosen" << std::endl;
			return base;
		case 2:
			base = new B;
			std::cout << "B chosen" << std::endl;
			return base;
		case 3:
			base = new C;
			std::cout << "C chosen" << std::endl;
			return base;
	}
	return base;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "The class is A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "The class is B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "The class is C" << std::endl;
	else
		std::cout << "Unknown class..." << std::endl;
}

void identify(Base &p)
{
	try { (void)dynamic_cast<A&>(p); std::cout << "The class is A" << std::endl; return;}
	catch(const std::exception& e) {}
	try { (void)dynamic_cast<B&>(p); std::cout << "The class is B" << std::endl; return;}
	catch(const std::exception& e) {}
	try { (void)dynamic_cast<C&>(p); std::cout << "The class is C" << std::endl; return;}
	catch(const std::exception& e) {}
	std::cout << "Unknown class..." << std::endl;
}


