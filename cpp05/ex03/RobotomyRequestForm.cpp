# include <iostream>
# include <cctype>
# include <string> 
# include <sstream>
# include <fstream>
# include <cstdlib>
#include <ctime>
# include "RobotomyRequestForm.hpp"
# include "Bureaucrat.hpp"
# define CONST_MSG "\033[1;32mDefault constructor RobotomyRequestForm called\033[0m"
# define CONST_N_MSG "\033[1;32mParametizered constructor RobotomyRequestForm called, Target: \033[0m"
# define CPY_CONST_MSG "\033[1;32mCopy constructor RobotomyRequestForm called\033[0m"
# define CPY_ASSIG_OP_MSG "Copy assignment operator called"
# define DEST_MSG "\033[1;31mDestructor RobotomyRequestForm called\033[0m"

RobotomyRequestForm::RobotomyRequestForm( void )
	: AForm("RobotomyRequestForm", "Default_target", false, 72, 45)
{
	std::cout << CONST_MSG << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( std::string Target )
	: AForm("RobotomyRequestForm", Target, false, 72, 45)
{
	std::cout << CONST_N_MSG << Target << std::endl;
}


RobotomyRequestForm::~RobotomyRequestForm( void )
{
	std::cout << DEST_MSG << " for RobotomyRequestForm. Target: " << Target_ << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const &src )
	: AForm(src)
{
	std::cout << CPY_CONST_MSG << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator= (RobotomyRequestForm const & rhs)
{
	std::cout << CPY_ASSIG_OP_MSG << std::endl;
    if (this != &rhs)
    {
        this->is_signed_ = rhs.is_signed_;
    }
    return *this;
}

std::ostream &operator<<( std::ostream &o,  RobotomyRequestForm &rhs )
{
	o << "RobotomyRequestForm Target: " << rhs.getTarget() << std::endl 
	<< "Is RobotomyRequestForm signed: " << rhs.isSigned() << std::endl
	<< "Minimum grade in order to sign " << rhs.getMinsign() << std::endl
	<< "Minimum grade in order to execute " << rhs.getMinexe()
	<< std::endl;
	return o;
}

std::string RobotomyRequestForm::getTarget() const
{
	return Target_;
}

std::string RobotomyRequestForm::isSigned() const
{
	if (is_signed_)
		return "Signed";
	return "Not signed";
}


std::string RobotomyRequestForm::getMinsign() const
{
    std::stringstream ss;
    ss << min_grade_sign_;
    return ss.str();
}

std::string RobotomyRequestForm::getMinexe() const
{
    std::stringstream ss;
    ss << min_grade_exe_;
    return ss.str();
}

const char* RobotomyRequestForm::GradeTooHighException::what() const throw() {
	return "\033[1;31mError\033[0m: Grade too hight (limit 1).";
}

const char* RobotomyRequestForm::GradeTooLowException::what() const throw() {
	return "\033[1;31mError\033[0m: Grade too low to achive the action.";
}

void RobotomyRequestForm::beSigned( Bureaucrat &bu)
{
	if (bu.getGrade() > min_grade_sign_)
	{
		std::cout << "The RobotomyRequestForm |" << this->getTarget() << "| couldn’t be signed by " << bu.getName()
		<< " because the bureaucrat doesn't meet the conditions"
		<< std::endl;
		throw RobotomyRequestForm::GradeTooLowException();
	}
	is_signed_ = true;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > min_grade_exe_)
	{
		std::cout << "The RobotomyRequestForm |" << this->getTarget() << "| couldn’t be signed by " << executor.getName()
		<< " because the bureaucrat doesn't meet the conditions"
		<< std::endl;
		throw RobotomyRequestForm::GradeTooLowException();
	}
	static bool seeded = false;
    if (!seeded) {
        std::srand(static_cast<unsigned>(std::time(NULL)));
        seeded = true;
    }
	if (std::rand() % 2 == 0)
	{
		std::cout << Target_ << " has been robotomized successfully!!!" << std::endl;
	}
	else
	{
		std::cout << "Robotomy to: "<< Target_ << " has falied... not robotomy today :(" << std::endl;
	}
}