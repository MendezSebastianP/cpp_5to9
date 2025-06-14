# include <iostream>
#include <cstdlib>
# include <cctype>
# include <limits>
# include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( void ) {}

BitcoinExchange::~BitcoinExchange( void ) {}

BitcoinExchange::BitcoinExchange( BitcoinExchange const &src )
{
	*this = src;
}

BitcoinExchange & BitcoinExchange::operator= (BitcoinExchange const & rhs)
{
	(void)rhs;
	return *this;
}

void BitcoinExchange::Print_Map(std::map<std::string, int> map, std::string sep)
{
	for ( std::map<std::string, int>::iterator i = map.begin(); i != map.end(); i++)
	{
		std::cout << i->first << sep << i->second << std::endl;
	}
	
}

void BitcoinExchange::Fill_database()
{
	int E_Rate;
	std::string Buffer;
	char col1[20];
	char col2[20];
	std::ifstream Bitcoindb("data.csv");
	getline(Bitcoindb, Buffer);
	while (getline(Bitcoindb, Buffer))
	{
		Buffer.copy(col1, 10, 0); // copying 10 characters (date) from the start
		col1[10] = '\0';
		Buffer.copy(col2, Buffer.length() - 11, 11); // copying len-11 characters, from after the date
		col2[Buffer.length() - 11] = '\0';
		E_Rate = std::atoi(col2); // transform col2 in int
		database_.insert(std::pair<std::string, int>(col1, E_Rate));
		// col1 = NULL; col2 = NULL;
	}
	Bitcoindb.close();
}
