#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <cctype>

class ScalarConverter {
    public:
	// canonic
	ScalarConverter( void );
	~ScalarConverter( void );

	void convert( int type, std::string input );

    private:
    int	find_type( std::string input );
	int ischar( std::string input, size_t len_input );
	int isint( std::string input, size_t len_input );
	int isfloat( std::string input, size_t len_input );
	int isdouble( std::string input, size_t len_input );
	int isinvalid( std::string input, size_t len_input );
};


#endif