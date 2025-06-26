# include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << ARG_ERR << std::endl;
		return (EXIT_FAILURE);
	}
	RPN rpn;
	rpn.GetInput(argv[1]);
	if (rpn.FillStack())
	{
		std::cerr << "Error: Invalid input." << std::endl;
		return (EXIT_FAILURE);
	}
	PrintStack(rpn.stack_);
	return (EXIT_SUCCESS);
}