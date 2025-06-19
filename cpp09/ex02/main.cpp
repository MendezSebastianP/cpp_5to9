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
	PrintVector(PmergeMe.vector_[0]);
	while (PmergeMe.DividePairsRest())
	{
		PrintVector(PmergeMe.vector_[0]);
	}
	PmergeMe.JacobsthalSec();
	PrintVector(PmergeMe.jacob_);
	return (EXIT_SUCCESS);
}