#ifndef BURREAUCRAT_HPP
# define BURREAUCRAT_HPP
# include <iostream>
# include <cctype>

class Bureaucrat {
    public:
	// canonic
	Bureaucrat( void );
	Bureaucrat( std::string Name );
	~Bureaucrat( void );
	Bureaucrat( Bureaucrat const &src);
	Bureaucrat & operator =( Bureaucrat const & rhs);


	class GradeTooHighException : public std::exception {};
	class GradeTooLowException : public std::exception {};

	void getGrade();
	void getName();

    protected:
    std::string const Name_;
	int	grade_;
};


#endif