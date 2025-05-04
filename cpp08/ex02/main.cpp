#include "MutantStack.hpp"

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

int main() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}



