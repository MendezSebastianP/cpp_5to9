# include <iostream>
# include <cctype>
# include "Bureaucrat.hpp"
# define CONST_MSG "\033[1;32mDefault constructor Bureaucrat called\033[0m"
# define CONST_N_MSG "\033[1;32mParametizered constructor Bureaucrat called, name: \033[0m"
# define CPY_CONST_MSG "\033[1;32mCopy constructor Bureaucrat called\033[0m"
# define CPY_ASSIG_OP_MSG "Copy assignment operator called"
# define DEST_MSG "\033[1;31mDestructor Bureaucrat called\033[0m"

Bureaucrat::Bureaucrat( void )
	: Name_("Empty")
{
	std::cout << CONST_MSG << std::endl;
}

Bureaucrat::Bureaucrat( std::string Name, int grade )
	: Name_(Name)
{
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	grade_ = grade;
	std::cout << CONST_N_MSG << Name << std::endl;
}


Bureaucrat::~Bureaucrat( void )
{
	std::cout << DEST_MSG << " for Bureaucrat. Name: " << Name_ << std::endl;
}

Bureaucrat::Bureaucrat( Bureaucrat const &src )
: Name_(src.Name_)
{
	std::cout << CPY_CONST_MSG << std::endl;
	this->grade_ = src.grade_;
}

Bureaucrat & Bureaucrat::operator= (Bureaucrat const & rhs)
{
	std::cout << CPY_ASSIG_OP_MSG << std::endl;
	this->grade_ = rhs.grade_;
	return *this;
}

std::ostream &operator<<( std::ostream &o,  Bureaucrat &rhs )
{
	o << "Bureaucrat name: " << rhs.getName() << ", bureaucrat grade " 
	<< rhs.getGrade() << std::endl;
	return o;
}

std::string Bureaucrat::getName() const
{
	return this->Name_;
}

int Bureaucrat::getGrade() const
{
	return this->grade_;
}

void Bureaucrat::decrementGrade()
{

	if (grade_ == 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	grade_++;
}

void Bureaucrat::incrementGrade()
{
	if (grade_ == 1)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	grade_--;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "\033[1;31mError\033[0m: Grade too hight (limit 1).";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "\033[1;31mError\033[0m: Grade too low (limit 150).";
}

void Bureaucrat::signAForm( AForm &form )
{
	form.beSigned(*this);
	if (form.isSigned() == "Signed")
	{
		std::cout << this->getName() << " signed " 
		<< form.getName() << ", to: " << form.getTarget() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) const
{
	form.execute(*this);
	if (form.isSigned() == "Signed")
	{
		std::cout << this->getName() << " executed " 
		<< form.getName() << ", to: " << form.getTarget() << std::endl;
	}
}
