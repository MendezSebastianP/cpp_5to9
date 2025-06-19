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
	int i, sep, block;
	const int n = vector_[0].size();

	if (n < (int)(pow(2, level_ + 1)))
		return (false);
	sep = static_cast<int>(pow(2, level_ - 1));
	i = sep - 1;
	FillBlocks();
	while (i + sep < n)
	{
		block = 0;
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

bool PmergeMe::Insertion(void)
{
	int i, sep, n, block;

	sep = static_cast<int>(pow(2, level_ - 1));
	n = vector_[0].size();
	if(n < sep * 3)
	{
		level_--;
		std::cout << "\nInsertion not possible\n";
		return (true);
	}
	;
}


