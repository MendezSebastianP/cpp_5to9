#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <fstream>
# include <string>
# include <string.h> 
# include <cctype>
# include <stack>
# include <cstdlib>
# include <sstream>
# define ARG_ERR "Please, give a valid argument: a list of integers without duplicates."



class PmergeMe {
	// canonic
    public:
	PmergeMe( void );
	~PmergeMe( void );
	PmergeMe( PmergeMe const &src );
	PmergeMe & operator =( PmergeMe const & rhs );

	int GetInput( char *str);
	int FillStack( void );

	
	private:
	std::stack<std::string> stack_;
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

// subject functions

int nmax(int n);
}

#endif