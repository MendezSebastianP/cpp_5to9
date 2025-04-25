#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP
# include <iostream>
# include <cctype>
# include "Bureaucrat.hpp"
# include "AForm.hpp"


class Bureaucrat;

class ShrubberyCreationForm : public AForm {
    public:
	// canonic
	ShrubberyCreationForm( void );
	ShrubberyCreationForm( std::string Target );
	~ShrubberyCreationForm( void );
	ShrubberyCreationForm( ShrubberyCreationForm const &src);
	ShrubberyCreationForm & operator =( ShrubberyCreationForm const & rhs);

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

std::ostream &operator<<( std::ostream &o,  ShrubberyCreationForm &rhs );

#endif