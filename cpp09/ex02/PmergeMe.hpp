#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <fstream>
# include <string>
# include <string.h> 
# include <cctype>
# include <vector>
# include <deque>
# include <cstdlib>
# include <sstream>
# include <cmath>
# include <algorithm>
# define ARG_ERR "Please, give a valid argument: a list of integers without duplicates."



class PmergeMe {
	// canonic
    public:
	PmergeMe( void );
	~PmergeMe( void );
	PmergeMe( PmergeMe const &src );
	PmergeMe & operator =( PmergeMe const & rhs );

	// init
	int GetInput( char *str);
	int FillVector( void );

	// utils
	void FillBlocks();
	void SwapBlocks(int a, int b);

	// swap functions
	void JacobsthalSec(void);
	bool DividePairsFirst( void );
	bool DividePairsRest( void );
	bool Insertion( void );
	
	std::vector< std::vector<int> > vector_;
	std::vector<int> jacob_;
	private:
	std::string input_;
	int level_;
};

// helpful functions/templates

void PrintVector(std::vector<int> vector);
double to_double(const std::string &str);
int to_int(const std::string &str);
bool is_number(const std::string& s);

template <typename T>
std::string to_string_easy(T value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

// subject functions

int nmax(int n);

#endif