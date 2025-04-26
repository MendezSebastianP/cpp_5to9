#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <iostream>
# include <cctype>
# include "Bureaucrat.hpp"
# include "AForm.hpp"


class Bureaucrat;

class RobotomyRequestForm : public AForm {
    public:
	// canonic
	RobotomyRequestForm( void );
	RobotomyRequestForm( std::string Target );
	~RobotomyRequestForm( void );
	RobotomyRequestForm( RobotomyRequestForm const &src);
	RobotomyRequestForm & operator =( RobotomyRequestForm const & rhs);

	class GradeTooHighException : public std::exception 
	{
		public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception 
	{
		public:
		virtual const char *what() const throw();
	};

	virtual void beSigned( Bureaucrat &bu);
	virtual void execute(Bureaucrat const & executor) const;
	std::string getTarget() const;
	std::string isSigned() const;
	std::string getMinsign() const;
	std::string getMinexe() const;
};

std::ostream &operator<<( std::ostream &o,  RobotomyRequestForm &rhs );

#endif