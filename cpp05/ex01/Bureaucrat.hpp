#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <cctype>
# include "Form.hpp"

class Form;

class Bureaucrat {
    public:
	// canonic
	Bureaucrat( void );
	Bureaucrat( std::string Name, int grade );
	~Bureaucrat( void );
	Bureaucrat( Bureaucrat const &src);
	Bureaucrat & operator =( Bureaucrat const & rhs);

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

	void signForm( Form &form );
	std::string getName();
	int getGrade();
	void incrementGrade();
	void decrementGrade();

    private:
    std::string const Name_;
	int	grade_;
};

std::ostream &operator<<( std::ostream &o,  Bureaucrat &rhs );

#endif