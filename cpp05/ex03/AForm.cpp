# include <iostream>
# include <cctype>
# include <string> 
# include <sstream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"
# define CONST_MSG "\033[1;32mDefault constructor AForm called\033[0m"
# define CONST_N_MSG "\033[1;32mParametizered constructor AForm called, Target: \033[0m"
# define CPY_CONST_MSG "\033[1;32mCopy constructor AForm called\033[0m"
# define CPY_ASSIG_OP_MSG "Copy assignment operator called"
# define DEST_MSG "\033[1;31mDestructor AForm called\033[0m"

AForm::AForm( void )
	: Target_("Empty"), Name_("Empty_name"), is_signed_(false), min_grade_sign_(50), min_grade_exe_(100)
{
	std::cout << CONST_MSG << std::endl;
}

AForm::AForm( std::string Name, std::string target, bool is_signed, int min_sign, int min_exe )
	: Target_(target), Name_(Name), is_signed_(is_signed), min_grade_sign_(min_sign), min_grade_exe_(min_exe)
{
	std::cout << CONST_N_MSG << target << std::endl;
}


AForm::~AForm( void )
{
	std::cout << DEST_MSG << " for AForm. Target: " << Target_ << std::endl;
}

AForm::AForm( AForm const &src )
	: Target_(src.Target_), min_grade_sign_(src.min_grade_sign_), 
	min_grade_exe_(src.min_grade_exe_)
{
	std::cout << CPY_CONST_MSG << std::endl;
}

AForm & AForm::operator= (AForm const & rhs)
{
	std::cout << CPY_ASSIG_OP_MSG << std::endl;
    if (this != &rhs)
    {
        this->is_signed_ = rhs.is_signed_;
    }
    return *this;
}

std::ostream &operator<<( std::ostream &o,  AForm &rhs )
{
	o << "AForm Target: " << rhs.getTarget() << std::endl 
	<< "Is AForm signed: " << rhs.isSigned() << std::endl
	<< "Minimum grade in order to sign " << rhs.getMinsign() << std::endl
	<< "Minimum grade in order to execute " << rhs.getMinexe()
	<< std::endl;
	return o;
}

std::string AForm::getTarget() const
{
	return Target_;
}

std::string AForm::getName() const
{
	return Name_;
}

std::string AForm::isSigned() const
{
	if (is_signed_)
		return "Signed";
	return "Not signed";
}


std::string AForm::getMinsign() const
{
    std::stringstream ss;
    ss << min_grade_sign_;
    return ss.str();
}

std::string AForm::getMinexe() const
{
    std::stringstream ss;
    ss << min_grade_exe_;
    return ss.str();
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "\033[1;31mError\033[0m: Grade too hight (limit 1).";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "\033[1;31mError\033[0m: Grade too low to achive the action.";
}

void AForm::beSigned( Bureaucrat &bu)
{
	if (bu.getGrade() > min_grade_sign_)
	{
		std::cout << "The AForm |" << this->getTarget() << "| couldn’t be signed by " << bu.getName()
		<< " because the bureaucrat doesn't meet the conditions"
		<< std::endl;
		throw AForm::GradeTooLowException();
	}
	is_signed_ = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > min_grade_exe_)
	{
		std::cout << "The AForm |" << this->getTarget() << "| couldn’t be signed by " << executor.getName()
		<< " because the bureaucrat doesn't meet the conditions"
		<< std::endl;
		throw AForm::GradeTooLowException();
	}
}