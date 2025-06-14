#ifndef BitcoinExchange_HPP
# define BitcoinExchange_HPP
# include <iostream>
# include <fstream>
# include <string> 
# include <cctype>
# include <map>
# include <cstdlib>
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

	int Fill_input( char *input ); // fill the input map
	int Fill_database(); // fill the database map
	void Findvalue(); // the main function, will find the value from ntokens according from its date in date db
	void Findclosest( std::map<std::string, double>::iterator iterator );
	void Error_handling( std::map<std::string, double>::iterator iterator );
	int IsValidInput( std::string str );
	bool IsValidDate( int month, int day, int year );

	// debug

	void Print_Map( std::map<std::string, double> map, std::string sep );

	std::map<std::string, double> database_;
	std::map<std::string, double> input_;
	private:
};

double to_double(std::string &str);

#endif