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
	// PrintVector(PmergeMe.vector_[0]);
	while (PmergeMe.DividePairsRest())
	{
		// PrintVector(PmergeMe.vector_[0]);
	}
	PmergeMe.JacobsthalSec();
	// PrintVector(PmergeMe.jacob_);
	// PrintVector(PmergeMe.vector_[0]);
	// PrintVector(PmergeMe.vector_[1]);
	// PrintVector(PmergeMe.vector_[2]);
	while (PmergeMe.Insertion())
	{
		// PrintVector(PmergeMe.vector_[0]);
	}
	bool sorted = std::adjacent_find(PmergeMe.vector_[0].begin(), PmergeMe.vector_[0].end(), std::greater<int>()) 
              == PmergeMe.vector_[0].end();
	if (!sorted) {
		std::cerr << "Not sorted!\n";
	}
	PrintVector(PmergeMe.vector_[0]);
	return (EXIT_SUCCESS);
}