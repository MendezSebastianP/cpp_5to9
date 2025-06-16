# include "RPN.hpp"

RPN::RPN( void ) {}

RPN::~RPN( void ) {}

RPN::RPN( RPN const &src )
{
	*this = src;
}

RPN & RPN::operator= (RPN const & rhs)
{
	(void)rhs;
	return *this;
}

bool is_number(const std::string& s) {
    std::istringstream iss(s);
    double d;
    return iss >> std::noskipws >> d && iss.eof();
}

double to_double(const std::string &str) 
{
	char* end;
	errno = 0;
	double x = std::strtod(str.c_str(), &end);
	return x;
}

int RPN::GetInput(char *str)
{
	input_= str;
	return (EXIT_SUCCESS);
}

int RPN::FillStack(void)
{
	std::istringstream stream(input_);
    std::string buffer;
	int n_num = 0, n_op = 0, block_n = 0;
    while (getline(stream, buffer, ' ')) 
	{
		if (buffer[0] == '\0')
			continue;
		if (!is_number(buffer) && (buffer.length() > 1 || buffer.find_first_of("/*-+") == std::string::npos))
			return (EXIT_FAILURE);
		if (buffer.find_first_of("/*-+") != std::string::npos)
		{
			if (block_n == 1)
				return (EXIT_FAILURE);
			n_op++;
			block_n = 0;
		}
		if (is_number(buffer))
		{
			n_num++;
			block_n++;
			if (to_double(buffer) >= 10)
				return (EXIT_FAILURE);
		}
        stack_.push(buffer);
    }
	if (n_num - 1 != n_op || block_n != 0)
		return (EXIT_FAILURE);
	InvertStack(stack_);
	return (EXIT_SUCCESS);
}

void InvertStack(std::stack<std::string> &stack)
{
    std::stack<std::string> tmp;

    while (!stack.empty()) {
        tmp.push(stack.top());
        stack.pop();
    }
    stack = tmp;
}

void PrintStack(std::stack<std::string> stack) {
    while (!stack.empty()) {
        std::cout << stack.top() << std::endl;
        stack.pop();
    }
}

int RPN::GetOperator(std::string &str)
{
	if (str.empty() || str.length() != 1)
	return INVALID_OP;

    switch (str[0])
	{
        case '+':
			return ADD_OP;
        case '-':
			return SUBTRACT_OP;
        case '*': 
			return MULTIPLY_OP;
        case '/':
			return DIVIDE_OP;
        default: 
			return INVALID_OP;
    }
}

void RPN::Operation()
{
	std::stack<std::string> tmp;
	double a, b, result;
	int op;
	int i = 0;

	while (stack_.size() > 2)
	{
		while(!stack_.empty() && is_number(stack_.top()))
		{
			// std::cout << stack_.top() << std::endl;
			tmp.push(stack_.top());
			stack_.pop();
		};
		op = GetOperator(stack_.top());
		if (op == 0)
			break;
		stack_.pop();
		// new function?
		InvertStack(tmp);
		b = to_double(tmp.top()); tmp.pop();
		a = to_double(tmp.top()); tmp.pop();
		switch (op) {
			case ADD_OP:
				result = a + b;
				break;

			case SUBTRACT_OP:
				result = a - b;
				break;

			case MULTIPLY_OP:
				result = a * b;
				break;

			case DIVIDE_OP:
				if (b == 0) {return;}
				result = a / b;
				break;

			default:
				return;
		}
		tmp.push(to_string_easy(result));
		InvertStack(tmp);
		// 
		while(!tmp.empty() && is_number(tmp.top()))
		{
			stack_.push(tmp.top());
			tmp.pop();
		}
		i++;
	}
}


