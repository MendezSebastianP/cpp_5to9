# include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << ARG_ERR << std::endl;
		return (EXIT_FAILURE);
	}
	PmergeMe PmergeMe;
	if (argc > 2)
		PmergeMe.ArrangeVector(argv);
	else
		PmergeMe.GetInput(argv[1]);
	if (PmergeMe.FillVector())
	{
		std::cerr << ARG_ERR << std::endl;
		return (EXIT_FAILURE);
	}
	while (PmergeMe.DividePairsRest())
	{}
	PmergeMe.JacobsthalSec();
	while (PmergeMe.Insertion()) {}
	std::vector<int> const & v = PmergeMe.getVector();
	bool sorted = std::adjacent_find(v.begin(), v.end(), std::greater<int>()) == v.end();
	if (!sorted) {
		std::cerr << "Not sorted!\n";
	}
	PrintVector(PmergeMe.getVector());
	return (EXIT_SUCCESS);
}