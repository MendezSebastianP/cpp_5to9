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

void BitcoinExchange::Print_Map(std::map<std::string, double> map, std::string sep)
{
	for ( std::map<std::string, double>::iterator i = map.begin(); i != map.end(); i++)
	{
		std::cout << i->first << sep << i->second << std::endl;
	}
	
}

double to_double(const std::string& s) {
	char* end;
	errno = 0;
	double x = std::strtod(s.c_str(), &end);
	return x;
}

int BitcoinExchange::Fill_database()
{
	double E_Rate;
	std::string Buffer;
	char col1[20];
	char col2[20];
	std::ifstream Bitcoindb("data.csv");
	if (Bitcoindb.fail())
	{
		std::cerr << "Error: Can not access to the data base file" << std::endl;
		return (EXIT_FAILURE);
	}
	getline(Bitcoindb, Buffer);
	while (getline(Bitcoindb, Buffer))
	{
		Buffer.copy(col1, 10, 0); // copying 10 characters (date) from the start
		col1[10] = '\0';
		Buffer.copy(col2, Buffer.length() - 11, 11); // copying len-11 characters, from after the date
		col2[Buffer.length() - 11] = '\0';
		E_Rate = to_double(col2); // transform col2 in int
		database_.insert(std::pair<std::string, double>(col1, E_Rate));
	}
	Bitcoindb.close();
	return (EXIT_SUCCESS);
}

int BitcoinExchange::Fill_input( char *input )
{
	int valid_code;
	double E_Rate;
	std::string Buffer;
	char col1[20];
	char col2[20];
	std::ifstream Bitcoindb(input);
	if (Bitcoindb.fail())
	{
		std::cerr << "Error: Can not access to the input file" << std::endl;
		return (EXIT_FAILURE);
	}
	getline(Bitcoindb, Buffer);
	while (getline(Bitcoindb, Buffer))
	{
		valid_code = IsValidInput(Buffer);
		if (valid_code) // enter if invalid input
		{
			input_.insert(std::pair<std::string, double>(std::string(1, char('0' + valid_code)), 0));
			continue ;
		}
		Buffer.copy(col1, 10, 0); // copying 10 characters (date) from the start
		col1[10] = '\0';
		Buffer.copy(col2, Buffer.length() - 13, 13); // copying len-13 characters, from after the date
		col2[Buffer.length() - 13] = '\0';
		E_Rate = to_double(col2); // transform col2 in int
		input_.insert(std::pair<std::string, double>(col1, E_Rate));
	}
	Bitcoindb.close();
	return (EXIT_SUCCESS);
}

int BitcoinExchange::IsValidInput(std::string str)
{
	int year, month, day;
	double value;
	char bufy[10], bufm[10], bufd[10], str_value[10];

	// check the lenght and form
	if (str.length() < 14 || str.length() > 17)
		return INVALID_INPUT;
	else if (str.find(" | ") == std::string::npos)
		return INVALID_INPUT;
	else if (str[4] != '-' || str[7] != '-' || str[10] != ' ' || str[11] != '|' || str[12] != ' ')
		return INVALID_INPUT;

	// check the date
	str.copy(bufy, 4, 0); // extract year
	bufy[4] = '\0';
	str.copy(bufm, 2, 5); // extract month
	bufm[2] = '\0';
	str.copy(bufd, 2, 8); // extract day
	bufd[2] = '\0';
	year = std::atoi(bufy);
	month = std::atoi(bufm);
	day = std::atoi(bufd);
	if (IsValidDate(month, day, year))
		return INVALID_DATE;

	// chacke the value
	str.copy(str_value, str.length() - 13, 13); // extract the value
	str_value[str.length() - 13] = '\0';
	value = to_double(str_value);
	if (value < 0)
		return TOO_SHORT_N;
	else if (value > 1000)
		return TOO_LONG_N;
	return (0);
}

bool BitcoinExchange::IsValidDate(int month, int day, int year)
{
    int status=0; 

    if ((month == 1 || month == 3 || month == 5 || month == 7 ||
        month == 8 || month == 10 || month == 12) && ( day>31 || day<1) )
    {
        status = 3; 
    }
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && (day>30 || day<1) )
    {
        status = 4; 
    }
    else if ((month == 2) && (year % 4 == 0) && (day>29 || day<1))
    {
        status = 5; 
    }
    else if ((month == 2) && (year % 4 != 0) && (day>28 || day<1) )
    {
        status = 6; 
    }
    else if ((year < 999) || (year > 10000))
    {
        status = 1;
    }
    if ((month < 1) || (month > 12))
    {
        status = 2;
    }
    return status;
}

