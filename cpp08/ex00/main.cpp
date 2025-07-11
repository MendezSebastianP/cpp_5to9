# include "Easyfind.hpp"

void sep( size_t n, std::string msg)
{
	std::cout << std::endl;
	for (size_t i = 0; i < n; i++)
		std::cout << "#########################################################################" << std::endl;
	std::cout << "                            " << msg << std::endl;
	for (size_t i = 0; i < n; i++)
		std::cout << "#########################################################################" << std::endl;
	std::cout << std::endl;
}

int main()
{
	std::vector<int>::iterator it;
	std::list<int>::iterator it2;
	std::deque<int>::iterator it3;
// 1) Test with vector
	sep(2, "VECTOR"); 
	std::vector<int> v; 
	int data[]= { 10, 20, 30, 40, 50 };
	for (size_t i = 0; i < 5; i++)
	{
		v.push_back(data[i]);
	}

	try {it = easyfind(v, 20);}
	catch(const std::exception& e) { std::cerr << e.what() << '\n';}
	if (it == v.end())
		std::cout << "Number not found in vector" << std::endl;
	else
		std::cout << "Found in vector: " << *it << "\n";
	try {it = easyfind(v, 25);}
	catch(const std::exception& e) { std::cerr << e.what() << '\n';}

// 2) Test with list
	sep(2, "LIST");
	std::list<int> l2; 
	int data2[]= { 10, 20, 30, 40, 50 };
	for (size_t i = 0; i < 5; i++)
	{
		l2.push_back(data2[i]);
	}

	try {it2 = easyfind(l2, 30);}
	catch(const std::exception& e) { std::cerr << e.what() << '\n';}
	if (it2 == l2.end())
		std::cout << "Number not found in vector" << std::endl;
	else
		std::cout << "Found in vector: " << *it2 << "\n";
	try {it2 = easyfind(l2, 35);}
	catch(const std::exception& e) { std::cerr << e.what() << '\n';}
	

// 3) Test with deque
	sep(2, "DEQUE");
	std::deque<int> l3; 
	int data3[]= { 10, 20, 30, 40, 50 };
	for (size_t i = 0; i < 5; i++)
	{
		l3.push_back(data3[i]);
	}

	
	try {it3 = easyfind(l3, 40);}
	catch(const std::exception& e) { std::cerr << e.what() << '\n';}
	if (it3 == l3.end())
		std::cout << "Number not found in vector" << std::endl;
	else
		std::cout << "Found in vector: " << *it3 << "\n";
	try {it3 = easyfind(l3, 45);}
	catch(const std::exception& e) { std::cerr << e.what() << '\n';}
}