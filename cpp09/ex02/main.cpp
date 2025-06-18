# include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << ARG_ERR << std::endl;
		return (EXIT_FAILURE);
	}
	PmergeMe PmergeMe;
	PmergeMe.GetInput(argv[1]);
	if (PmergeMe.FillVector())
	{
		std::cerr << ARG_ERR << std::endl;
		return (EXIT_FAILURE);
	}
	PrintVector(PmergeMe.vector_);
	while (PmergeMe.DividePairsRest())
	{
		PrintVector(PmergeMe.vector_);
	}
	PmergeMe.JacobstalSec();
	PrintVector(PmergeMe.jacob_);
	return (EXIT_SUCCESS);
}