#ifndef BURREAUCRAT_HPP
# define BURREAUCRAT_HPP
# include <iostream>
# include <cctype>

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

	std::string getName();
	int getGrade();
	void incrementGrade();
	void decrementGrade();

    protected:
    std::string const Name_;
	int	grade_;
};

std::ostream &operator<<( std::ostream &o,  Bureaucrat &rhs );

#endif