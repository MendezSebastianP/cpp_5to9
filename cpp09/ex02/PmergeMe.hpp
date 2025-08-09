#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include <cstddef>

class PmergeMe {
public:
    // Sort using merge-insertion (Ford–Johnson) for std::vector
    static void sortVector(std::vector<int>& v);
    // Sort using merge-insertion (Ford–Johnson) for std::deque
    static void sortDeque(std::deque<int>& d);

private:
    // vector helpers
    static void fjSortVector(std::vector<int>& v);
    static void buildPairsVector(const std::vector<int>& v,
                                 std::vector< std::pair<int,int> >& pairs,
                                 bool& hasOdd, int& oddVal);
    static void insertPendantsVector(std::vector<int>& mainChain,
                                     const std::vector< std::pair<int,int> >& pairs);

    // deque helpers
    static void fjSortDeque(std::deque<int>& d);
    static void buildPairsDeque(const std::deque<int>& d,
                                std::vector< std::pair<int,int> >& pairs,
                                bool& hasOdd, int& oddVal);
    static void insertPendantsDeque(std::deque<int>& mainChain,
                                    const std::vector< std::pair<int,int> >& pairs);

    // shared helper to compute Jacobsthal insertion order (0-based pair indices)
    static std::vector<size_t> jacobInsertionOrder(size_t nPairs);
};

#endif // PMERGEME_HPP