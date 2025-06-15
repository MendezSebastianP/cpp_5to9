#ifndef BitcoinExchange_HPP
# define BitcoinExchange_HPP
# include <iostream>
# include <fstream>
# include <string> 
# include <cctype>
# include <map>
# include <cstdlib>
#include <sstream>
# define ARG_ERR "Please, put only one argument: a valid file with header, \" | \" separated with the date and an amount of Bitcoins per line"
# define INVALID_INPUT 1
# define INVALID_DATE 2
# define TOO_SHORT_N 3
# define TOO_LONG_N 4


class BitcoinExchange {
	// canonic
    public:
	BitcoinExchange( void );
	~BitcoinExchange( void );
	BitcoinExchange( BitcoinExchange const &src );
	BitcoinExchange & operator =( BitcoinExchange const & rhs );

	// 
	int ShowRate( char *input ); // fill the input map
	int FillDatabase(); // fill the database map
	void FindClosest( unsigned int date, double E_Rate ); // put the rate of the closest old date
	int IsValidInput( std::string str ); // check if the value is valid and return an error code
	bool IsValidDate( int month, int day, int year ); // check if the date is valid
	unsigned int DateToInt( std::string str); // convert a date format in int format

	// debug
	void Print_Map( std::map<unsigned int, double> map, std::string sep );

	private:
	std::map< unsigned int, double> database_;
};

// helpful functions/templates to convert

double to_double(std::string &str);

template <typename T>
std::string to_string_easy(T value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

#endif