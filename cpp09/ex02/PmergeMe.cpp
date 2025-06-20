# include "PmergeMe.hpp"

PmergeMe::PmergeMe( void ) 
	: level_(1) 
{
	vector_.resize(3);
}

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

int to_int(const std::string &str) 
{
	char* end;
	errno = 0;
	int x = std::atoi(str.c_str());
	return x;
}

void PrintVector(std::vector<int> vector) 
{
    for (size_t i = 0; i < vector.size(); ++i) {
        std::cout << vector[i];
        if (i + 1 < vector.size())
            std::cout << ' ';
    }
    std::cout << '\n';
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

int PmergeMe::FillVector(void)
{
	std::istringstream stream(input_);
    std::string buffer;
	int num = 0;
    while (getline(stream, buffer, ' ')) 
	{
		if (buffer[0] == '\0')
			continue;
		if (!is_number(buffer))
			return (EXIT_FAILURE);
		num = to_int(buffer);
        for (size_t i = 0; i < vector_[0].size(); ++i)
        {
            if (vector_[0][i] == num)
				return (EXIT_FAILURE);
        }
		vector_[0].insert(vector_[0].end(), num);
		vector_[1].insert(vector_[1].end(), 0);
		vector_[2].insert(vector_[2].end(), 0);
    }
	return (EXIT_SUCCESS);
}

bool PmergeMe::DividePairsFirst()
{
	int i = 0, sep = 0;
	const int n = vector_[0].size();

	if (n < (int)(pow(2, level_ + 1)))
		return (true);
	sep = 1;
	while (i + 1 < n)
	{
		std::cout << "sep " << sep << " i: " << i << " vector compares " << i <<"|" <<(i+sep) <<  std::endl;
		if (vector_[0][(i)] > vector_[0][(i + sep)])
			std::swap(vector_[0][(i)], vector_[0][(i + sep)]);
		i += 2;
	}
	level_++;
	return (false);
}
void PmergeMe::FillBlocks()
{
	int sep, n, block;
	
	sep = static_cast<int>(pow(2, level_ - 1));
	n = vector_[0].size();
	block = 0;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < sep; j++)
		{
			vector_[1][i + j] = block;
		}
		block++;
	}
}

void PmergeMe::SwapBlocks(int a, int b)
{
	int sep, index_a, index_b;
	
	sep = static_cast<int>(pow(2, level_ - 1));
	index_a = ((std::upper_bound(vector_[1].begin(), vector_[1].end(), a)) - vector_[1].begin()) - 1;
	index_b = ((std::upper_bound(vector_[1].begin(), vector_[1].end(), b)) - vector_[1].begin()) - 1;
	for (int i = 0; std::abs(i) < sep; i--)
	{
		std::swap(vector_[0][(i + a)], vector_[0][(i + b)]);
		std::swap(vector_[1][(i + a)], vector_[1][(i + b)]);
		std::swap(vector_[2][(i + a)], vector_[2][(i + b)]);
	}
}

bool PmergeMe::DividePairsRest()
{
	int i, sep;
	const int n = vector_[0].size();

	if (n < (int)(pow(2, level_ + 1)))
		return (false);
	sep = static_cast<int>(pow(2, level_ - 1));
	i = sep - 1;
	FillBlocks();
	while (i + sep < n)
	{
		std::cout << "sep " << sep << " i: " << i << " vector compares " << i <<"|" <<(i+sep) <<  std::endl;
		if (vector_[0][(i)] > vector_[0][(i + sep)])
		{
			SwapBlocks(i, i + sep);
		}
		i += (sep * 2);
	}
	level_++;
	return (true);
}

void PmergeMe::JacobsthalSec(void)
{
	int n = 0, size = vector_[0].size();

	jacob_.insert(jacob_.end(), 0);
	jacob_.insert(jacob_.end(), 1);

	std::cout << jacob_.max_size() << std::endl;
	while (jacob_.back() < size)
	{
		jacob_.insert(jacob_.end(), jacob_[n + 1] + (2 * jacob_[n]));
		n++;
	}
}

void PmergeMe::FillMainPend()
{
	int sep, n;
	
	sep = static_cast<int>(pow(2, level_ - 1));
	n = vector_[0].size();
	for (size_t i = 0; i < n; i++)
	{
		if (vector_[1][i] % 2 == 0 && vector_[1][i] != 0)
			vector_[2][i] = 1;
		else
			vector_[2][i] = 0;
	}
	for (size_t i = n; i %% sep == 0; i--)
	{
		vector_[2][i] = 2;
	}
	
}

bool PmergeMe::Insertion(void)
{
	int i, j, sep, n, block, j_number, index_pend, lib;

	sep = static_cast<int>(pow(2, level_ - 1));
	n = vector_[0].size();
	if(n < sep * 3)
	{
		level_--;
		std::cout << "\nInsertion not possible\n";
		return (true);
	}
	FillBlocks();
	FillMainPend();
	j = 3; // index 3 is the jacobsthal 3 number, the first used in the sequence

	// as our blocks are numbers from 0 to n, b1, b2, etc are our even numbers
	// so if we want to use the jacobstal numbers as j_3 -> b3, b3 would have
	// and index of 4, as 0 = b1, 1 = a1, 2 = b2, 3 = a2, 4 = b4.  We will find the
	// right index with: (j_number - 1) * 2. So we use the j_number to find the
	// rioight index.

	// 1.	loop for set j_number (find the last index block (LIB) if b3 and then b2)
	// 1.1	for each iteration find the (LIB) from the numbers to search:
	//		until bound element. if b3, until a3, if b2 until b2. taking into account
	//		the  !! prevoius swaps !!.
	// 2.	do the binary search between these numbers
	// 3.	swap them
	// 4.	change pend numbers in vector_[2]
	// 5.	increment all the numbers in order to be consistent

	
	j_number = (jacob_[j] - 1) * 2;
	index_pend = ((std::upper_bound(vector_[1].begin(), vector_[1].end(), j_number)) - vector_[1].begin()) - 1;
	while(j_number <= 0)
	{
		lib = ((std::upper_bound(vector_[1].begin(), vector_[1].end(), j_number + 1)) - vector_[1].begin()) - 1;


		j_number -= 2; // we go through the even numbers, as b3- > b2
	}

	return (true);
}

void PmergeMe::FillLibn(int j_number)
{
	int lib, bound;

	for (size_t i = 0; i < vector; i++)
	{
		if (vector_[1].ma)
		lib = ((std::upper_bound(vector_[1].begin(), vector_[1].end(), j_number - 1)) - vector_[1].begin()) - 1;
		if (vector[2][lib] == 0)
			break;
		else
			j_number--;
	}
}


