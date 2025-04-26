#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include <cctype>
# include "AForm.hpp"

class AForm;

class Intern {
    public:
	// canonic
	Intern( void );
	~Intern( void );
	Intern( Intern const &src);
	Intern & operator =( Intern const & rhs);
	Intern( const std::string form, const std::string target );

	AForm *makeForm(const std::string form, const std::string target);
};



#endif