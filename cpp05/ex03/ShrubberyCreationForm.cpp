# include <iostream>
# include <cctype>
# include <string> 
# include <sstream>
#include <fstream>
# include "ShrubberyCreationForm.hpp"
# include "Bureaucrat.hpp"
# define CONST_MSG "\033[1;32mDefault constructor ShrubberyCreationForm called\033[0m"
# define CONST_N_MSG "\033[1;32mParametizered constructor ShrubberyCreationForm called, Target: \033[0m"
# define CPY_CONST_MSG "\033[1;32mCopy constructor ShrubberyCreationForm called\033[0m"
# define CPY_ASSIG_OP_MSG "Copy assignment operator called"
# define DEST_MSG "\033[1;31mDestructor ShrubberyCreationForm called\033[0m"

ShrubberyCreationForm::ShrubberyCreationForm( void )
	: AForm("ShrubberyCreationForm", "Default_target", false, 145, 137)
{
	std::cout << CONST_MSG << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string Target )
	: AForm("ShrubberyCreationForm", Target, false, 145, 137)
{
	std::cout << CONST_N_MSG << Target << std::endl;
}


ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	std::cout << DEST_MSG << " for ShrubberyCreationForm. Target: " << Target_ << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const &src )
	: AForm(src)
{
	std::cout << CPY_CONST_MSG << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator= (ShrubberyCreationForm const & rhs)
{
	std::cout << CPY_ASSIG_OP_MSG << std::endl;
    if (this != &rhs)
    {
        this->is_signed_ = rhs.is_signed_;
    }
    return *this;
}

std::ostream &operator<<( std::ostream &o,  ShrubberyCreationForm &rhs )
{
	o << "ShrubberyCreationForm Target: " << rhs.getTarget() << std::endl 
	<< "Is ShrubberyCreationForm signed: " << rhs.isSigned() << std::endl
	<< "Minimum grade in order to sign " << rhs.getMinsign() << std::endl
	<< "Minimum grade in order to execute " << rhs.getMinexe()
	<< std::endl;
	return o;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return Target_;
}

std::string ShrubberyCreationForm::isSigned() const
{
	if (is_signed_)
		return "Signed";
	return "Not signed";
}


std::string ShrubberyCreationForm::getMinsign() const
{
    std::stringstream ss;
    ss << min_grade_sign_;
    return ss.str();
}

std::string ShrubberyCreationForm::getMinexe() const
{
    std::stringstream ss;
    ss << min_grade_exe_;
    return ss.str();
}

const char* ShrubberyCreationForm::GradeTooHighException::what() const throw() {
	return "\033[1;31mError\033[0m: Grade too hight (limit 1).";
}

const char* ShrubberyCreationForm::GradeTooLowException::what() const throw() {
	return "\033[1;31mError\033[0m: Grade too low to achive the action.";
}

void ShrubberyCreationForm::beSigned( Bureaucrat &bu)
{
	if (bu.getGrade() > min_grade_sign_)
	{
		std::cout << "The ShrubberyCreationForm |" << this->getTarget() << "| couldn’t be signed by " << bu.getName()
		<< " because the bureaucrat doesn't meet the conditions"
		<< std::endl;
		throw ShrubberyCreationForm::GradeTooLowException();
	}
	is_signed_ = true;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > min_grade_exe_)
	{
		std::cout << "The ShrubberyCreationForm |" << this->getTarget() << "| couldn’t be signed by " << executor.getName()
		<< " because the bureaucrat doesn't meet the conditions"
		<< std::endl;
		throw ShrubberyCreationForm::GradeTooLowException();
	}

    // 1) open the source file
    std::ifstream  in("tree.txt");
    if (!in.is_open())
        throw std::runtime_error("Could not open tree.txt");

    // 2) open the target file
    std::string outName = this->getTarget() + "_shrubbery";
    std::ofstream out(outName.c_str());
    if (!out.is_open())
        throw std::runtime_error("Could not create " + outName);

    // 3) copy all characters from in → out
    out << in.rdbuf();
}