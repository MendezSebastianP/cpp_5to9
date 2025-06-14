#ifndef BitcoinExchange_HPP
# define BitcoinExchange_HPP
# include <iostream>
#include <fstream> 
# include <cctype>
# include <map>
# include <cstdlib>
# define ARG_ERR "Please, put only one argument: a valid file with header, \" | \" separated with the date and an amount of Bitcoins per line"

class BitcoinExchange {
	// canonic
    public:
	BitcoinExchange( void );
	~BitcoinExchange( void );
	BitcoinExchange( BitcoinExchange const &src );
	BitcoinExchange & operator =( BitcoinExchange const & rhs );

	void Fill_input( char *input ); // fill the input map
	void Fill_database(); // fill the database map
	void Findvalue(); // the main function, will find the value from ntokens according from its date in date db
	void Findclosest( std::map<std::string, int>::iterator iterator );
	void Error_handling( std::map<std::string, int>::iterator iterator );

	// debug

	void Print_Map( std::map<std::string, int> map, std::string sep );

	std::map<std::string, int> database_;
	std::map<std::string, int> input_;
	private:
};



#endif