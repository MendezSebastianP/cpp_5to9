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
// 1) Test with vector
	sep(2, "VECTOR");
	std::vector<int> v; 
	int data[]= { 10, 20, 30, 40, 50 };
	for (size_t i = 0; i < 5; i++)
	{
		v.push_back(data[i]);
	}

	std::vector<int>::iterator it = easyfind(v, 20);
	if (it == v.end())
		std::cout << "Number not found in vector" << std::endl;
	else
		std::cout << "Found in vector: " << *it << "\n";
	sep(0, "NOT VALID");
	it = easyfind(v, 25);
	if (it == v.end())
		std::cout << "Number not found in vector" << std::endl;
	else
		std::cout << "Found in vector: " << *it << "\n";
	
	it = easyfind(v, 0);
	if (it == v.end())
		std::cout << "Number not found in vector" << std::endl;
	else
		std::cout << "Found in vector: " << *it << "\n";

// 2) Test with list
	sep(2, "LIST");
	std::list<int> l2; 
	int data2[]= { 10, 20, 30, 40, 50 };
	for (size_t i = 0; i < 5; i++)
	{
		l2.push_back(data2[i]);
	}

	std::list<int>::iterator it2 = easyfind(l2, 30);
	if (it2 == l2.end())
		std::cout << "Number not found in list" << std::endl;
	else
		std::cout << "Found in list: " << *it2 << "\n";
	sep(0, "NOT VALID");
	it2 = easyfind(l2, 25);
	if (it2 == l2.end())
		std::cout << "Number not found in list" << std::endl;
	else
		std::cout << "Found in list: " << *it2 << "\n";
	
	it2 = easyfind(l2, 0);
	if (it2 == l2.end())
		std::cout << "Number not found in list" << std::endl;
	else
		std::cout << "Found in list: " << *it2 << "\n";

// 3) Test with deque
	sep(2, "DEQUE");
	std::deque<int> l3; 
	int data3[]= { 10, 20, 30, 40, 50 };
	for (size_t i = 0; i < 5; i++)
	{
		l3.push_back(data3[i]);
	}

	std::deque<int>::iterator it3 = easyfind(l3, 40);
	if (it3 == l3.end())
		std::cout << "Number not found in deque" << std::endl;
	else
		std::cout << "Found in deque: " << *it3 << "\n";
	sep(0, "NOT VALID");
	it3 = easyfind(l3, 25);
	if (it3 == l3.end())
		std::cout << "Number not found in deque" << std::endl;
	else
		std::cout << "Found in deque: " << *it3 << "\n";
	
	it3 = easyfind(l3, 0);
	if (it3 == l3.end())
		std::cout << "Number not found in deque" << std::endl;
	else
		std::cout << "Found in deque: " << *it3 << "\n";

}