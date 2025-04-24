#ifndef AForm_HPP
# define AForm_HPP
# include <iostream>
# include <cctype>
# include "Bureaucrat.hpp"


class Bureaucrat;

class AForm {
    public:
	// canonic
	AForm( void );
	AForm( std::string Name );
	~AForm( void );
	AForm( AForm const &src);
	AForm & operator =( AForm const & rhs);

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

std::ostream &operator<<( std::ostream &o,  AForm &rhs );

#endif