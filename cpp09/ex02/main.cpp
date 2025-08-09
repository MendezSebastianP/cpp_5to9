#include "PmergeMe.hpp"

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <cstring>
#include <cstdlib>
#include <cerrno>
#include <ctime>
#include <cctype>
#include <algorithm>

static bool parsePositiveInt(const std::string& s, int& out) {
    if (s.empty()) return false;
    for (size_t i = 0; i < s.size(); ++i) if (!std::isdigit(static_cast<unsigned char>(s[i]))) return false;
    errno = 0; long v = std::strtol(s.c_str(), 0, 10);
    if (errno != 0 || v < 0 || v > 2147483647) return false;
    out = static_cast<int>(v);
    return true;
}

static void printSeq(const char* prefix, const std::vector<int>& v) {
    std::cout << prefix;
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) std::cout << ' ';
        std::cout << v[i];
    }
    std::cout << '\n';
}

static bool isSortedAscending(const std::vector<int>& v) {
    for (size_t i = 1; i < v.size(); ++i) if (v[i-1] > v[i]) return false;
    return true;
}

int main(int argc, char** argv)
{
    if (argc < 2) { std::cerr << "Error\n"; return 1; }

    std::vector<int> input; input.reserve(argc-1);
    std::vector<int> seen;

    // separated space list
    for (int i = 1; i < argc; ++i) {
        std::istringstream ss(argv[i]);
        std::string tok;
        while (ss >> tok) {
            int x; if (!parsePositiveInt(tok, x)) { std::cerr << "Error\n"; return 1; }
            // linear duplicate detection
            if (std::find(seen.begin(), seen.end(), x) != seen.end()) { std::cerr << "Error\n"; return 1; }
            seen.push_back(x);
            input.push_back(x);
        }
    }

    if (input.empty()) { std::cerr << "Error\n"; return 1; }

    std::vector<int> v = input;
    std::deque<int> d(input.begin(), input.end());

    printSeq("Before: ", input);

    std::clock_t c1 = std::clock();
    PmergeMe::sortVector(v);
    std::clock_t c2 = std::clock();
    double tV = (double)(c2 - c1) * 1e6 / (double)CLOCKS_PER_SEC;

    std::clock_t c3 = std::clock();
    PmergeMe::sortDeque(d);
    std::clock_t c4 = std::clock();
    double tD = (double)(c4 - c3) * 1e6 / (double)CLOCKS_PER_SEC;

    printSeq("After:  ", v);

    if (!isSortedAscending(v)) {
        std::cout << "Not sorted\n";
    }

    std::cout.setf(std::ios::fixed);
    std::cout.precision(5);
    std::cout << "Time to process a range of " << input.size() << " elements with std::vector : " << tV << " us\n";
    std::cout << "Time to process a range of " << input.size() << " elements with std::deque  : " << tD << " us\n";

    return 0;
}