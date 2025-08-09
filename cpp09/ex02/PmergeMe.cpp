#include "PmergeMe.hpp"

#include <limits>
#include <map>
#include <algorithm>
#include <iterator>
#include <iostream>

// Jacobsthal numbers: J(0)=0, J(1)=1, J(n)=J(n-1)+2*J(n-2)
static std::vector<size_t> jacobSeqUntil(size_t limit) {
    std::vector<size_t> j; j.reserve(64);
    j.push_back(0); j.push_back(1);
    while (j.back() < limit) j.push_back(j[j.size()-1] + 2*j[j.size()-2]);
    return j;
}

std::vector<size_t> PmergeMe::jacobInsertionOrder(size_t nPairs) {
    std::vector<size_t> order;
    if (nPairs == 0) return order;
    std::vector<size_t> j = jacobSeqUntil(nPairs);
    for (size_t k = 2; k + 1 < j.size(); ++k) {
        size_t a = j[k];
        size_t b = std::min(j[k+1], nPairs);
        for (size_t idx = b; idx > a; --idx) order.push_back(idx - 1);
        if (b == nPairs) break;
    }
    std::vector<bool> seen(nPairs, false);
    for (size_t s = 0; s < order.size(); ++s) seen[order[s]] = true;
    for (size_t i = nPairs; i > 0; --i) if (!seen[i-1]) order.push_back(i-1);
    return order;
}

// Vector implementation

void PmergeMe::buildPairsVector(const std::vector<int>& v, std::vector< std::pair<int,int> >& pairs, bool& hasOdd, int& oddVal) {
    pairs.clear(); hasOdd = false; oddVal = 0;
    size_t i = 0; size_t n = v.size();
    for (; i + 1 < n; i += 2) {
        int a = v[i], b = v[i+1];
        if (a <= b) pairs.push_back(std::make_pair(a, b));
        else pairs.push_back(std::make_pair(b, a));
    }
    if (i < n) { hasOdd = true; oddVal = v[i]; }
}

static inline size_t ubPos(const std::vector<int>& arr, int val) {
    return static_cast<size_t>(std::upper_bound(arr.begin(), arr.end(), val) - arr.begin());
}

struct BigSecondCmp { bool operator()(const std::pair<int,int>& x, const std::pair<int,int>& y) const { return x.second < y.second; } };

static std::vector<size_t> localJacobOrder(size_t nPairs) {
    std::vector<size_t> order; if (!nPairs) return order;
    std::vector<size_t> j = jacobSeqUntil(nPairs);
    for (size_t k = 2; k + 1 < j.size(); ++k) {
        size_t a = j[k]; size_t b = std::min(j[k+1], nPairs);
        for (size_t idx = b; idx > a; --idx) order.push_back(idx - 1);
        if (b == nPairs) break;
    }
    std::vector<bool> seen(nPairs, false);
    for (size_t s = 0; s < order.size(); ++s) seen[order[s]] = true;
    for (size_t i = nPairs; i > 0; --i) if (!seen[i-1]) order.push_back(i-1);
    return order;
}

// Step1
static void ReorderStep1(std::vector< std::pair<int,int> >& pairs) {
    for (size_t groupSize = 1; groupSize < pairs.size(); groupSize *= 2) {
        for (size_t i = 0; i + 2 * groupSize <= pairs.size(); i += 2 * groupSize) {
            size_t leftLast  = i + groupSize - 1;
            size_t rightLast = i + 2 * groupSize - 1;
            if (pairs[leftLast].second > pairs[rightLast].second) {
                std::rotate(pairs.begin() + i,
                            pairs.begin() + i + groupSize,
                            pairs.begin() + i + 2 * groupSize);
            }
        }
    }
}

// Manual merge sort
static void sortPairsByBig(std::vector< std::pair<int,int> >& pairs) {
    if (pairs.size() < 2) return;
    std::vector< std::pair<int,int> > tmp(pairs.size());
    for (size_t width = 1; width < pairs.size(); width *= 2) {
        for (size_t i = 0; i < pairs.size(); i += 2 * width) {
            size_t mid = std::min(i + width, pairs.size());
            size_t end = std::min(i + 2 * width, pairs.size());
            size_t a = i, b = mid, k = i;
            while (a < mid && b < end) {
                if (pairs[a].second <= pairs[b].second) tmp[k++] = pairs[a++];
                else                                   tmp[k++] = pairs[b++];
            }
            while (a < mid) tmp[k++] = pairs[a++];
            while (b < end) tmp[k++] = pairs[b++];
            for (size_t t = i; t < end; ++t) pairs[t] = tmp[t];
        }
    }
}

static void buildMainChain(std::vector<int>& out, const std::vector< std::pair<int,int> >& pairs, bool hasOdd, int oddVal) 
{
    if (pairs.empty()) { out.clear(); if (hasOdd) out.push_back(oddVal); return; }
    out.clear();
    out.push_back(pairs[0].first);
    out.push_back(pairs[0].second);
    for (size_t i = 1; i < pairs.size(); ++i) out.push_back(pairs[i].second);
    std::vector<size_t> order = localJacobOrder(pairs.size());
    for (size_t oi = 0; oi < order.size(); ++oi) {
        size_t idx = order[oi]; if (idx == 0) continue;
        int small = pairs[idx].first; int big = pairs[idx].second;
        size_t posBig = static_cast<size_t>(std::find(out.begin(), out.end(), big) - out.begin());
        size_t pos = static_cast<size_t>(std::upper_bound(out.begin(), out.begin() + posBig, small) - out.begin());
        out.insert(out.begin() + pos, small);
    }
    if (hasOdd) { size_t pos = ubPos(out, oddVal); out.insert(out.begin() + pos, oddVal); }
}

void PmergeMe::fjSortVector(std::vector<int>& v) 
{
    if (v.size() <= 1) return;
    std::vector< std::pair<int,int> > pairs; bool hasOdd=false; int oddVal=0;
    buildPairsVector(v, pairs, hasOdd, oddVal);
    ReorderStep1(pairs);
    // // Step1 debug
    // {
    //     std::cout << "Step1: ";
    //     for (size_t pi = 0; pi < pairs.size(); ++pi) {
    //         if (pi) std::cout << ' ';
    //         std::cout << pairs[pi].first << ' ' << pairs[pi].second;
    //     }
    //     if (hasOdd) std::cout << ' ' << oddVal; // show trailing odd if present
    //     std::cout << '\n';
    // }
    sortPairsByBig(pairs);
    std::vector<int> mainChain; mainChain.reserve(v.size());
    buildMainChain(mainChain, pairs, hasOdd, oddVal);
    v.swap(mainChain);
}

void PmergeMe::sortVector(std::vector<int>& v) { fjSortVector(v); }

// Deque 

static inline size_t ubPosDeque(const std::deque<int>& arr, int val) {
    return static_cast<size_t>(std::upper_bound(arr.begin(), arr.end(), val) - arr.begin());
}

void PmergeMe::buildPairsDeque(const std::deque<int>& d, std::vector< std::pair<int,int> >& pairs, bool& hasOdd, int& oddVal) {
    pairs.clear(); hasOdd = false; oddVal = 0;
    size_t i = 0; size_t n = d.size();
    for (; i + 1 < n; i += 2) {
        int a = d[i], b = d[i+1];
        if (a <= b) pairs.push_back(std::make_pair(a, b));
        else pairs.push_back(std::make_pair(b, a));
    }
    if (i < n) { hasOdd = true; oddVal = d[i]; }
}

static std::vector<size_t> localJacobOrderDeque(size_t nPairs) { return localJacobOrder(nPairs); }

static void buildMainChainDeque(std::deque<int>& out, const std::vector< std::pair<int,int> >& pairs, bool hasOdd, int oddVal) {
    if (pairs.empty()) { out.clear(); if (hasOdd) out.push_back(oddVal); return; }
    out.clear();
    out.push_back(pairs[0].first);
    out.push_back(pairs[0].second);
    for (size_t i = 1; i < pairs.size(); ++i) out.push_back(pairs[i].second);
    std::vector<size_t> order = localJacobOrderDeque(pairs.size());
    for (size_t oi = 0; oi < order.size(); ++oi) {
        size_t idx = order[oi]; if (idx == 0) continue;
        int small = pairs[idx].first; int big = pairs[idx].second;
        size_t posBig = static_cast<size_t>(std::find(out.begin(), out.end(), big) - out.begin());
        size_t pos = static_cast<size_t>(std::upper_bound(out.begin(), out.begin() + posBig, small) - out.begin());
        out.insert(out.begin() + pos, small);
    }
    if (hasOdd) { size_t pos = ubPosDeque(out, oddVal); out.insert(out.begin() + pos, oddVal); }
}

void PmergeMe::fjSortDeque(std::deque<int>& d) {
    if (d.size() <= 1) return;
    std::vector< std::pair<int,int> > pairs; bool hasOdd=false; int oddVal=0;
    buildPairsDeque(d, pairs, hasOdd, oddVal);
    ReorderStep1(pairs);
    // (Optional) could print deque Step1 too; keeping quiet to avoid duplication
    sortPairsByBig(pairs);
    std::deque<int> mainChain; mainChain.resize(0);
    buildMainChainDeque(mainChain, pairs, hasOdd, oddVal);
    d.assign(mainChain.begin(), mainChain.end());
}

void PmergeMe::sortDeque(std::deque<int>& d) { fjSortDeque(d); }


