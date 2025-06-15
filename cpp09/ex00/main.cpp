# include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << ARG_ERR << std::endl;
		return (EXIT_FAILURE);
	}
	BitcoinExchange Bitcoin;
	if (Bitcoin.FillDatabase() || Bitcoin.ShowRate(argv[1]))
	{
		return (EXIT_FAILURE);
	}
	// Bitcoin.Print_Map(Bitcoin.database_, " | ");
	return (EXIT_SUCCESS);
}