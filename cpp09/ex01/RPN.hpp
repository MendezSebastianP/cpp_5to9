#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <fstream>
# include <string>
# include <string.h> 
# include <cctype>
# include <stack>
# include <cstdlib>
# include <sstream>
# define ARG_ERR "Please, put only one argument: numbers and operators in one token"
# define INVALID_OP 0
# define ADD_OP 1
# define SUBTRACT_OP 2
# define MULTIPLY_OP 3
# define DIVIDE_OP 4


class RPN {
	// canonic
    public:
	RPN( void );
	~RPN( void );
	RPN( RPN const &src );
	RPN & operator =( RPN const & rhs );

	int GetInput( char *str);
	int FillStack( void );
	void Operation();
	int GetOperator( std::string &str);
	std::stack<std::string> stack_;
	
	private:
	std::string input_;
};

// helpful functions/templates

void PrintStack(std::stack<std::string> stack);
void InvertStack( std::stack<std::string> &stack);
double to_double(const std::string &str);
bool is_number(const std::string& s);

template <typename T>
std::string to_string_easy(T value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

#endif