# include <iostream>
# include <cctype>
# include "Intern.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# define CONST_MSG "\033[1;32mDefault constructor Intern called\033[0m"
# define CONST_N_MSG "\033[1;32mParametizered constructor Intern called\033[0m"
# define CPY_CONST_MSG "\033[1;32mCopy constructor Intern called\033[0m"
# define CPY_ASSIG_OP_MSG "Copy assignment operator called"
# define DEST_MSG "\033[1;31mDestructor Intern called\033[0m"

Intern::Intern( void )
{
	std::cout << CONST_MSG << std::endl;
}


Intern::~Intern( void )
{
	std::cout << DEST_MSG << " for Intern." << std::endl;
}

Intern::Intern( Intern const &src )
{
	std::cout << CPY_CONST_MSG << std::endl;
	// intern doesnt have any variables...
	*this = src;
}

Intern & Intern::operator= (Intern const & rhs)
{
	std::cout << CPY_ASSIG_OP_MSG << std::endl;
	if (this == &rhs)
		return *this;
	// intern doesnt have any variables...
	return *this;
}

AForm* createShrubberyForm(const std::string target) 
{
	return new ShrubberyCreationForm(target);
}

AForm* createRobotomyForm(const std::string target)
{
	return new RobotomyRequestForm(target);
}
AForm* createPardonForm(const std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string formName, const std::string target) {
    // Step 1: Define all possible forms we can create
    struct FormType {
        std::string name;
        AForm* (*creator)(const std::string);
    };

    // Step 2: Create a list of available forms with their creation functions
    const FormType availableForms[] = {
        {"ShrubberyCreationForm", &createShrubberyForm},
        {"RobotomyRequestForm", &createRobotomyForm},
        {"PresidentialPardonForm", &createPardonForm}
    };
    const int formCount = sizeof(availableForms) / sizeof(availableForms[0]);

    // Step 3: Search for matching form type
    for (int i = 0; i < formCount; ++i) {
        if (formName == availableForms[i].name) {
            std::cout << "Intern creates " << formName << std::endl;
            return availableForms[i].creator(target);
        }
    }

    // Step 4: Handle unknown form type
    std::cout << "Warning: Intern can't create unknown form '"
              << formName << "'" << std::endl;
    return NULL;
}
