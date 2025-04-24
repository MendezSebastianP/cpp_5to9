#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <cctype>
# include "Bureaucrat.hpp"


class Bureaucrat;

class Form {
    public:
	// canonic
	Form( void );
	Form( std::string Name );
	~Form( void );
	Form( Form const &src);
	Form & operator =( Form const & rhs);

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

	void beSigned( Bureaucrat &bu);
	std::string getName() const;
	std::string isSigned() const;
	std::string getMinsign() const;
	std::string getMinexe() const;

    private:
    std::string const Name_;
	bool is_signed_;
	int const min_grade_sign_;
	int const min_grade_exe_;

};

std::ostream &operator<<( std::ostream &o,  Form &rhs );

#endif