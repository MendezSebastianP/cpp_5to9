# include <iostream>
# include <cctype>
# include <string> 
# include <sstream>
#include <fstream>
# include "PresidentialPardonForm.hpp"
# include "Bureaucrat.hpp"
# define CONST_MSG "\033[1;32mDefault constructor PresidentialPardonForm called\033[0m"
# define CONST_N_MSG "\033[1;32mParametizered constructor PresidentialPardonForm called, Target: \033[0m"
# define CPY_CONST_MSG "\033[1;32mCopy constructor PresidentialPardonForm called\033[0m"
# define CPY_ASSIG_OP_MSG "Copy assignment operator called"
# define DEST_MSG "\033[1;31mDestructor PresidentialPardonForm called\033[0m"

PresidentialPardonForm::PresidentialPardonForm( void )
	: AForm("PresidentialPardonForm", "Default_target", false, 25, 5)
{
	std::cout << CONST_MSG << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( std::string Target )
	: AForm("PresidentialPardonForm", Target, false, 25, 5)
{
	std::cout << CONST_N_MSG << Target << std::endl;
}


PresidentialPardonForm::~PresidentialPardonForm( void )
{
	std::cout << DEST_MSG << " for PresidentialPardonForm. Target: " << Target_ << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const &src )
	: AForm(src)
{
	std::cout << CPY_CONST_MSG << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator= (PresidentialPardonForm const & rhs)
{
	std::cout << CPY_ASSIG_OP_MSG << std::endl;
    if (this != &rhs)
    {
        this->is_signed_ = rhs.is_signed_;
    }
    return *this;
}

std::ostream &operator<<( std::ostream &o,  PresidentialPardonForm &rhs )
{
	o << "PresidentialPardonForm Target: " << rhs.getTarget() << std::endl 
	<< "Is PresidentialPardonForm signed: " << rhs.isSigned() << std::endl
	<< "Minimum grade in order to sign " << rhs.getMinsign() << std::endl
	<< "Minimum grade in order to execute " << rhs.getMinexe()
	<< std::endl;
	return o;
}

std::string PresidentialPardonForm::getTarget() const
{
	return Target_;
}

std::string PresidentialPardonForm::isSigned() const
{
	if (is_signed_)
		return "Signed";
	return "Not signed";
}


std::string PresidentialPardonForm::getMinsign() const
{
    std::stringstream ss;
    ss << min_grade_sign_;
    return ss.str();
}

std::string PresidentialPardonForm::getMinexe() const
{
    std::stringstream ss;
    ss << min_grade_exe_;
    return ss.str();
}

const char* PresidentialPardonForm::GradeTooHighException::what() const throw() {
	return "\033[1;31mError\033[0m: Grade too hight (limit 1).";
}

const char* PresidentialPardonForm::GradeTooLowException::what() const throw() {
	return "\033[1;31mError\033[0m: Grade too low to achive the action.";
}

void PresidentialPardonForm::beSigned( Bureaucrat &bu)
{
	if (bu.getGrade() > min_grade_sign_)
	{
		std::cout << "The PresidentialPardonForm |" << this->getTarget() << "| couldn’t be signed by " << bu.getName()
		<< " because the bureaucrat doesn't meet the conditions"
		<< std::endl;
		throw PresidentialPardonForm::GradeTooLowException();
	}
	is_signed_ = true;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > min_grade_exe_)
	{
		std::cout << "The PresidentialPardonForm |" << this->getTarget() << "| couldn’t be signed by " << executor.getName()
		<< " because the bureaucrat doesn't meet the conditions"
		<< std::endl;
		throw PresidentialPardonForm::GradeTooLowException();
	}
	std::cout << Target_ << "has been pardoned by Zaphod Beeblebrox." << std::endl;
}