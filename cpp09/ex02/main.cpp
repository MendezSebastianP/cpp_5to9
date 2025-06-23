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
	std::cout << "Before \n\n";
	PrintVector(PmergeMe.vector_[0]);
	PrintVector(PmergeMe.vector_[1]);
	PrintVector(PmergeMe.vector_[2]);
	std::cout << "After \n\n";
	while (PmergeMe.Insertion())
	{
		PrintVector(PmergeMe.vector_[0]);
	}
	return (EXIT_SUCCESS);
}