// PmergeMe.hpp
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
#include <iterator>

class PmergeMe {
public:
    template<typename T>
    struct Paired {
        T main; // The larger element in the pair
        T pend; // The smaller element in the pair
    };

    template<typename Container>
    static void sort(Container& arr) {
        _comparisons = 0;
        if (arr.size() <= 1) {
            return;
        }
        mergeInsertionSort(arr);
    }

    static size_t getComparisons() {
        return _comparisons;
    }

private:
    static size_t _comparisons;

    template<typename Container>
    static void mergeInsertionSort(Container& arr);

    template<typename Iterator, typename ValueType>
    static Iterator binarySearch(Iterator begin, Iterator end, const ValueType& value);
};

#endif
