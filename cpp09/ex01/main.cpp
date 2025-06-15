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
	rpn.FillStack();
	rpn.Operation();
	PrintStack(rpn.stack_);
	return (EXIT_SUCCESS);
}