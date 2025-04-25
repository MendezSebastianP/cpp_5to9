#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include <iostream>
# include <cctype>
# include "Bureaucrat.hpp"
# include "AForm.hpp"


class Bureaucrat;

class PresidentialPardonForm : public AForm {
    public:
	// canonic
	PresidentialPardonForm( void );
	PresidentialPardonForm( std::string Target );
	~PresidentialPardonForm( void );
	PresidentialPardonForm( PresidentialPardonForm const &src);
	PresidentialPardonForm & operator =( PresidentialPardonForm const & rhs);

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

std::ostream &operator<<( std::ostream &o,  PresidentialPardonForm &rhs );

#endif