#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <cctype>

class ScalarConverter {
	private:
	// canonic
	ScalarConverter( void );
	~ScalarConverter( void );
	ScalarConverter( ScalarConverter const &src);
	ScalarConverter & operator =( ScalarConverter const & rhs);
	
    public:
	static void convert( const std::string &input );

};

int	find_type( std::string input );
int ischar( std::string input, size_t len_input );
int isint( std::string input, size_t len_input );
int isfloat( std::string input, size_t len_input );
int isdouble( std::string input, size_t len_input );

void convert_char( std::string input );
void convert_int( std::string input );
void convert_float( std::string input );
void convert_double( std::string input );
void invalid( std::string input );


#endif