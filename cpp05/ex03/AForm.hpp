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
	AForm( std::string Target, std::string target, bool is_signed, int min_sign, int min_exe );
	virtual ~AForm( void );
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

	virtual void beSigned( Bureaucrat &bu) = 0;
	virtual void execute(Bureaucrat const & executor) const;
	virtual std::string getTarget() const;
	virtual std::string getName() const;
	virtual std::string isSigned() const;
	virtual std::string getMinsign() const;
	virtual std::string getMinexe() const;

    protected:
    std::string const Target_;
	std::string const Name_;
	bool is_signed_;
	int const min_grade_sign_;
	int const min_grade_exe_;

};

std::ostream &operator<<( std::ostream &o,  AForm &rhs );

#endif