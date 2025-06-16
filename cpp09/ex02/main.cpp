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
	if (PmergeMe.FillStack())
	{
		std::cerr << "Error: Invalid input." << std::endl;
		return (EXIT_FAILURE);
	}
	PmergeMe.Operation();
	PrintStack(PmergeMe.stack_);
	return (EXIT_SUCCESS);
}