# include "PmergeMe.hpp"

PmergeMe::PmergeMe( void ) 
	: level_(1) 
{
	vector_.resize(3);
	lib_n_.resize(2);
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

std::vector<int> PmergeMe::getVector()
{
	return (vector_[0]);
}

void PrintVector(std::vector<int> vector) 
{
    for (size_t i = 0; i < vector.size(); ++i) 
	{
        std::cout << vector[i];
		if (vector[i] < 10)
			std::cout << ' ';
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

void PmergeMe::ArrangeVector( char *args[] )
{
	for(int i = 1; args[i]; i++)
	{
		input_.replace(input_.size(), strlen(args[i]), args[i]);
		input_.replace(input_.size(), 1, " ");
	}
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
		if (num < 0)
			return (EXIT_FAILURE);
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
		// std::cout << "sep " << sep << " i: " << i << " vector compares " << i <<"|" <<(i+sep) <<  std::endl;
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
	for (size_t i = 0; i < n; i += sep)
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

	if (n < (int)(pow(2, level_)))
	{
		// std::cout << "n: " << n << ". pow op: " << (int)(pow(2, level_ + 1)) << std::endl;
		return (false);
	}
	sep = static_cast<int>(pow(2, level_ - 1));
	i = sep - 1;
	FillBlocks();
	while (i + sep < n)
	{
		// std::cout << "sep " << sep << " i: " << i << " vector compares " << i <<"|" <<(i+sep) <<  std::endl;
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

	// std::cout << jacob_.max_size() << std::endl;
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
	for (size_t i = n; i % sep != 0; --i)
	{
		vector_[2][i - 1] = 2;
	}
	
}

bool PmergeMe::Insertion(void)
{
	int i, j, sep, n, block, j_number, index_pend, lib;
	static int lvl_in;

	sep = static_cast<int>(pow(2, level_ - 1));
	n = vector_[0].size();
	if(n < sep * 3)
	{
		level_--;
		// std::cout << "\nInsertion not possible\n";
		return (true);
	}
	FillBlocks();
	FillMainPend();
	// std::cout << std::endl;
	// PrintVector(vector_[0]);
	// PrintVector(vector_[1]);
	// PrintVector(vector_[2]);
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
	// 3.	swap them... Act ually not. We insert it to the right place and then we delete
	//		the old one... do not forget to insert and delete the content in the 3 vectors
	// 4.	change pend numbers in vector_[2]
	// 5.	increment all the numbers in order to be consistent

	while (std::count(vector_[2].begin(), vector_[2].end(), 1) > 0)
	{
		// PrintVector(vector_[2]);
		j_number = (jacob_[j] - 1) * 2;
		for (int i = jacob_[j - 1]; i < jacob_[j]; i++)
		{
			// index_pend = ((std::upper_bound(vector_[1].begin(), vector_[1].end(), j_number)) - vector_[1].begin()) - 1;
			// std::cout << "jacob:" << jacob_[j] << ". j_number: " << j_number << std::endl;
			index_pend = ((std::find(vector_[1].begin(), vector_[1].end(), j_number)) - vector_[1].begin()) - 1 + sep;
			// std::cout << "index_pend" << index_pend << "\n";
			if (index_pend + 1 >= vector_[0].size())
			{
				index_pend = ((std::upper_bound(vector_[2].begin(), vector_[2].end(), 1)) - vector_[2].begin()) - 1;
				// std::cout << "limit 1\n";
			}
			if (vector_[2][index_pend] != 1)
			{
				index_pend = ((std::find(vector_[2].begin(), vector_[2].end(), 1))) - vector_[2].begin() + sep - 1;
				// std::cout << "limit 1.1\n";
			}
			FillLibn(j_number);
			lib = (std::upper_bound(lib_n_[0].begin(), lib_n_[0].end(), vector_[0][index_pend])) - lib_n_[0].begin();
			if (lib > 0) --lib;
			// std::cout << "Level: " << level_ << ". lib index: " << lib << ". lib number: " << lib_n_[0][lib] << 
				// ". index_pend: " << index_pend << ". From: " << vector_[0][index_pend] << std::endl;
			lib = lib_n_[1][lib];
			// std::cout << "lib index in vector:" << lib << "\n";
			BlockInsertion(lib, index_pend, sep);
			// PrintVector(vector_[0]);
			// PrintVector(vector_[1]);
			// PrintVector(vector_[2]);
			j_number -= 2; // we go through the even numbers, as b3- > b2
			if (std::count(vector_[2].begin(), vector_[2].end(), 1) == 0)
				break ;
		}
		j++;
	}
	// std::cout << "LOOP DONE, LVL DOWN ###################\n\n\n";
	level_--;
	if (level_ <= 0)
		return (false);
	else
		return (true);
}

void PmergeMe::BlockInsertion(int index_main, int index_pend, int sep)
{
    int start = index_pend - (sep - 1);
    std::vector<int> tmp0, tmp1;
    tmp0.insert(tmp0.end(), vector_[0].begin() + start, vector_[0].begin() + start + sep);
    tmp1.insert(tmp1.end(), vector_[1].begin() + start, vector_[1].begin() + start + sep);
    vector_[0].erase(vector_[0].begin() + start, vector_[0].begin() + start + sep);
    vector_[1].erase(vector_[1].begin() + start, vector_[1].begin() + start + sep);
    vector_[2].erase(vector_[2].begin() + start, vector_[2].begin() + start + sep);
	// std::cout << "main " << vector_[0][index_main] << ". pend " << tmp0[sep - 1] << std::endl;
	// std::cout << "main index " << index_main << ". pend index " << index_pend << std::endl;

    if (index_main < sep && sep == 1 && vector_[0][index_main] < tmp0[sep - 1]) {
		vector_[0].insert(vector_[0].begin() + 1, tmp0.begin(), tmp0.end());
        // vector_[1].insert(vector_[1].begin() + 1, tmp1.begin(), tmp1.end());

        vector_[1].insert(vector_[1].begin() + 1, sep, 0);
        vector_[2].insert(vector_[2].begin() + 1, sep, 0);
		// std::cout << "here3\n";
    }
    else if (index_main < sep && vector_[0][index_main] < tmp0[sep - 1]) {
        vector_[0].insert(vector_[0].begin() + sep, tmp0.begin(), tmp0.end());
        // vector_[1].insert(vector_[1].begin() + sep, tmp1.begin(), tmp1.end());

        vector_[1].insert(vector_[1].begin() + sep, sep, 0);
        vector_[2].insert(vector_[2].begin() + sep, sep, 0);
		// std::cout << "here4\n";
    }
    else if (index_main < sep) {
        vector_[0].insert(vector_[0].begin(), tmp0.begin(), tmp0.end());
        // vector_[1].insert(vector_[1].begin(), tmp1.begin(), tmp1.end());

        vector_[1].insert(vector_[1].begin(), sep, 0);
        vector_[2].insert(vector_[2].begin(), sep, 0);
		// std::cout << "here1\n";
    }
    else {
        vector_[0].insert(vector_[0].begin() + (index_main + 1), tmp0.begin(), tmp0.end());
        // vector_[1].insert(vector_[1].begin() + (index_main + 1), tmp1.begin(), tmp1.end());

        vector_[1].insert(vector_[1].begin() + (index_main + 1), sep, 0);
        vector_[2].insert(vector_[2].begin() + (index_main + 1), sep, 0);
		// std::cout << "here2\n";
    }
}




// void PmergeMe::BlockInsertion(int index_main, int index_pend, int sep)
// {
// 	std::vector<int> v_tmp0;
// 	std::vector<int> v_tmp1;
// 	std::vector<int> v_tmp2;
	
// 	for (int i = 0; i < sep; i++)
// 	{
// 		v_tmp0.insert(v_tmp.end(), vector_[0][index_pend - (sep - 1) + i]);
// 		v_tmp1.insert(v_tmp.end(), vector_[1][index_pend - (sep - 1) + i]);
// 		v_tmp2.insert(v_tmp.end(), vector_[2][index_pend - (sep - 1) + i]);
// 		vector_[0].erase(vector_[0].begin() + (index_pend - (sep - 1) + i));
// 		vector_[1].erase(vector_[1].begin() + (index_pend - (sep - 1) + i));
// 		vector_[2].erase(vector_[2].begin() + (index_pend - (sep - 1) + i));
// 	}

// 	if(index_main < sep && sep == 1 && vector_[0][index_main] < v_tmp[0])
// 	{
// 		std::cout << "main " << vector_[0][index_main] << ". pend " << v_tmp[0] << std::endl;
// 		std::cout << "main index " << index_main << ". pend index " << index_pend << std::endl;

// 		vector_[0].insert(vector_[0].begin() + 1, v_tmp[0]);
// 		vector_[1].insert(vector_[1].begin() + 1, v_tmp[1]);
// 		vector_[2].insert(vector_[2].begin() + 1, 0);
// 		std::cout << "here3\n";
// 	}
// 	else if(index_main < sep && vector_[0][index_main] < v_tmp[0])
// 	{
// 		vector_[0].insert(vector_[0].begin() + sep, v_tmp[0]);
// 		vector_[1].insert(vector_[1].begin() + sep + i, v_tmp[1]);
// 		vector_[2].insert(vector_[2].begin() + sep + i, 0);
// 		std::cout << "here4\n";
// 	}
// 	else if(index_main < sep)
// 	{
// 		vector_[0].insert(vector_[0].begin() + i, v_tmp[0]);
// 		vector_[1].insert(vector_[1].begin() + i, v_tmp[1]);
// 		vector_[2].insert(vector_[2].begin() + i, 0);
// 		std::cout << "here1\n";
// 	}
// 	else
// 	{
// 		vector_[0].insert(vector_[0].begin() + (index_main + 1 + i), v_tmp[0]);
// 		vector_[1].insert(vector_[1].begin() + (index_main + 1 + i), v_tmp[1]);
// 		vector_[2].insert(vector_[2].begin() + (index_main + 1 + i), 0);
// 		std::cout << "here2\n";
// 	}
// }

void PmergeMe::FillLibn(int j_number)
{
	int lib, bound, sep;

	sep = static_cast<int>(pow(2, level_ - 1));
	// empty the vector before, in order to avoid errors
	lib_n_[0].clear();
	lib_n_[1].clear();
	lib = ((std::upper_bound(vector_[1].begin(), vector_[1].end(), j_number - 1)) - vector_[1].begin()) - 1;
	if (lib + 1 >= vector_[0].size())
	{
		lib = ((std::lower_bound(vector_[2].begin(), vector_[2].end(), 1)) - vector_[2].begin()) - 1;
		// std::cout << "limit 2\n";
	}
	// std::cout << "\n\nFILL TEST ##################\n";
	// PrintVector(vector_[0]);
	// PrintVector(vector_[1]);
	// PrintVector(vector_[2]);
	// std::cout << "FillLibn test, lib number: " << vector_[0][lib] << ". lib index:" << lib << ". Sep: " << sep << std::endl;
	for (int i = lib; i >= 0; i -= sep)
	{
		// std::cout << "FillLibn test, i: " << i << ". Number: " << vector_[0][i] << ". j_number: " << j_number << std::endl;
		if (vector_[2][i] == 0)
		{
			lib_n_[0].insert(lib_n_[0].begin(),vector_[0][i]);
			lib_n_[1].insert(lib_n_[1].begin(), i);
		}
	}
	// PrintVector(lib_n_[0]);
	// lib = ((std::upper_bound(vector_[1].begin(), vector_[1].end(), j_number)) - vector_[1].begin()) - 1;
	// SwapBlocks();
	// for (size_t i = 0; i < sep; i++)
	// {
	// 	vector_[2][lib - sep] = 0;
	// }
}


