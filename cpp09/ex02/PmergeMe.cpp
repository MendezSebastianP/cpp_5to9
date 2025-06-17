# include "PmergeMe.hpp"

PmergeMe::PmergeMe( void ) {}

PmergeMe::~PmergeMe( void ) {}

PmergeMe::PmergeMe( PmergeMe const &src )
{
	*this = src;
}

PmergeMe & PmergeMe::operator= (PmergeMe const & rhs)
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

int nmax(int n)
{
    int sum = 0;
    for (int k = 1; k <= n; ++k) {
        double value = (3.0 / 4.0) * k;
        sum += static_cast<int>(ceil(log2(value)));
    }
    return sum;
}

int PmergeMe::GetInput(char *str)
{
	input_= str;
	return (EXIT_SUCCESS);
}




