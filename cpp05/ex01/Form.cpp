# include <iostream>
# include <cctype>
# include <string> 
# include <sstream>
# include "Form.hpp"
# include "Bureaucrat.hpp"
# define CONST_MSG "\033[1;32mDefault constructor Form called\033[0m"
# define CONST_N_MSG "\033[1;32mParametizered constructor Form called, name: \033[0m"
# define CPY_CONST_MSG "\033[1;32mCopy constructor Form called\033[0m"
# define CPY_ASSIG_OP_MSG "Copy assignment operator called"
# define DEST_MSG "\033[1;31mDestructor Form called\033[0m"

Form::Form( void )
	: Name_("Empty"), is_signed_(false), min_grade_sign_(50), min_grade_exe_(100)
{
	std::cout << CONST_MSG << std::endl;
}

Form::Form( std::string Name )
	: Name_(Name), is_signed_(false), min_grade_sign_(50), min_grade_exe_(100)
{
	std::cout << CONST_N_MSG << Name << std::endl;
}


Form::~Form( void )
{
	std::cout << DEST_MSG << " for Form. Name: " << Name_ << std::endl;
}

Form::Form( Form const &src )
	: Name_(src.Name_), min_grade_sign_(src.min_grade_sign_), 
	min_grade_exe_(src.min_grade_exe_)
{
	std::cout << CPY_CONST_MSG << std::endl;
}

Form & Form::operator= (Form const & rhs)
{
	std::cout << CPY_ASSIG_OP_MSG << std::endl;
    if (this != &rhs)
    {
        this->is_signed_ = rhs.is_signed_;
    }
    return *this;
}

std::ostream &operator<<( std::ostream &o,  Form &rhs )
{
	o << "Form name: " << rhs.getName() << std::endl 
	<< "Is form signed: " << rhs.isSigned() << std::endl
	<< "Minimum grade in order to sign " << rhs.getMinsign() << std::endl
	<< "Minimum grade in order to execute " << rhs.getMinexe()
	<< std::endl;
	return o;
}

std::string Form::getName() const
{
	return Name_;
}

std::string Form::isSigned() const
{
	if (is_signed_)
		return "Signed";
	return "Not signed";
}


std::string Form::getMinsign() const
{
    std::stringstream ss;
    ss << min_grade_sign_;
    return ss.str();
}

std::string Form::getMinexe() const
{
    std::stringstream ss;
    ss << min_grade_exe_;
    return ss.str();
}

const char* Form::GradeTooHighException::what() const throw() {
	return "\033[1;31mError\033[0m: Grade too hight (limit 1).";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "\033[1;31mError\033[0m: Grade too low to sign (min 50).";
}

void Form::beSigned( Bureaucrat &bu)
{
	if (bu.getGrade() > min_grade_sign_)
	{
		throw Form::GradeTooLowException();
	}
	is_signed_ = true;
}