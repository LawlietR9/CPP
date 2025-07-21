#include "PmergeMe.hpp"

size_t PmergeMe::_comparisons = 0;

// Binary search implementation that counts comparisons.
// It is designed to work with iterators that may not be random-access.
template<typename Iterator, typename ValueType>
Iterator PmergeMe::binarySearch(Iterator begin, Iterator end, const ValueType& value) {
    Iterator low = begin;
    Iterator high = end;
    while (std::distance(low, high) > 0) {
        Iterator mid = low;
        std::advance(mid, std::distance(low, high) / 2);
        _comparisons++; // Count each comparison
        if (*mid < value) {
            low = mid;
            std::advance(low, 1);
        } else {
            high = mid;
        }
    }
    return low;
}

// Jacobsthal numbers sequence used for efficient insertion ordering.
static const int JACOBSTHAL_NUMBERS[] = {
    0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691
};

// The core implementation of the Ford-Johnson (Merge-Insertion) algorithm.
template<typename Container>
void PmergeMe::mergeInsertionSort(Container& arr) {
    typedef typename Container::value_type ValueType;
    typedef Paired<ValueType> Pair;
    typedef std::vector<Pair> PairVector;

    if (arr.size() <= 1) {
        return;
    }

    // 1. Handle the stray element if the container size is odd.
    bool has_stray = arr.size() % 2 != 0;
    ValueType stray;
    if (has_stray) {
        stray = arr.back();
        arr.pop_back();
    }

    // 2. Create pairs and sort them internally (larger element becomes `main`).
    PairVector pairs;
    for (size_t i = 0; i < arr.size(); i += 2) {
        _comparisons++;
        if (arr[i] > arr[i + 1]) {
            Pair p;
            p.main = arr[i];
            p.pend = arr[i + 1];
            pairs.push_back(p);
        } else {
            Pair p;
            p.main = arr[i + 1];
            p.pend = arr[i];
            pairs.push_back(p);
        }
    }

    // 3. Recursively sort the pairs based on their `main` elements.
    if (pairs.size() > 1) {
        Container main_elements;
        for (size_t i = 0; i < pairs.size(); ++i) {
            main_elements.push_back(pairs[i].main);
        }
        mergeInsertionSort(main_elements);

        PairVector sorted_pairs;
        std::vector<bool> used(pairs.size(), false);
        for (size_t i = 0; i < main_elements.size(); ++i) {
            for (size_t j = 0; j < pairs.size(); ++j) {
                if (!used[j] && main_elements[i] == pairs[j].main) {
                    sorted_pairs.push_back(pairs[j]);
                    used[j] = true;
                    break;
                }
            }
        }
        pairs = sorted_pairs;
    }

    // 4. Create the main chain `S` and the pending elements chain `P`.
    Container S;
    std::vector<ValueType> P;
    for (size_t i = 0; i < pairs.size(); ++i) {
        S.push_back(pairs[i].main);
        P.push_back(pairs[i].pend);
    }

    // 5. Insert the first pending element at the beginning of S.
    if (!P.empty()) {
        S.insert(S.begin(), P[0]);
    }

    // 6. Insert the rest of the pending elements using Jacobsthal sequence.
    size_t last_jac = 1;
    for (size_t k = 2; last_jac < P.size(); ++k) {
        size_t current_jac = JACOBSTHAL_NUMBERS[k];
        if (current_jac > P.size()) {
            current_jac = P.size();
        }

        for (size_t i = current_jac; i > last_jac; --i) {
            ValueType& value_to_insert = P[i - 1];
            
            // The search for p_i is bounded by its corresponding s_i.
            ValueType& main_element_limit = pairs[i - 1].main;
            typename Container::iterator search_end_it = std::find(S.begin(), S.end(), main_element_limit);

            typename Container::iterator insert_pos = binarySearch(S.begin(), search_end_it, value_to_insert);
            S.insert(insert_pos, value_to_insert);
        }
        last_jac = current_jac;
    }

    // 7. Insert the stray element if it exists.
    if (has_stray) {
        S.insert(binarySearch(S.begin(), S.end(), stray), stray);
    }

    arr.swap(S);
}

// Explicit template instantiation for vector and deque of unsigned int.
template void PmergeMe::mergeInsertionSort<std::vector<unsigned int> >(std::vector<unsigned int>&);
template void PmergeMe::mergeInsertionSort<std::deque<unsigned int> >(std::deque<unsigned int>&);
