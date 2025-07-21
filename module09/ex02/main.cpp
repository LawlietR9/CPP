#include "PmergeMe.hpp"
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

static bool isPositiveInteger(const std::string& s) {
    if (s.empty()) return false;
    for (size_t i = 0; i < s.size(); ++i) {
        if (!isdigit(s[i]))
			return false;
    }
    if (s.length() > 1 && s[0] == '0')
		return false;
    return true;
}

long theoreticalUpperBound(int n) {
    if (n <= 1) return 0;
    long sum = 0;
    for (int i = 1; i <= n; ++i) {
        double val = 3.0 * i / 4.0;
        if (val > 0) {
            sum += std::ceil(std::log2(val));
        }
    }
    return sum;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error: No input sequence." << std::endl;
        return 1;
    }

    std::vector<unsigned int> inputVec;
    for (int i = 1; i < argc; ++i) {
        std::string s(argv[i]);
        if (!isPositiveInteger(s)) {
            std::cerr << "Error: Invalid input " << s << std::endl;
            return 1;
        }
        char* end;
        long val = std::strtol(s.c_str(), &end, 10);
        if (*end != '\0' || val < 0 || val > 2147483647) {
            std::cerr << "Error: Invalid or out-of-range input " << s << std::endl;
            return 1;
        }
        inputVec.push_back(static_cast<unsigned int>(val));
    }

    std::cout << "Before:";
    for (size_t i = 0; i < inputVec.size(); ++i)
        std::cout << " " << inputVec[i];
    std::cout << std::endl;

    std::vector<unsigned int> vec = inputVec;
    clock_t startVec = clock();
    PmergeMe::sort(vec);
    clock_t endVec = clock();
    size_t vec_comparisons = PmergeMe::getComparisons();

    std::deque<unsigned int> deq(inputVec.begin(), inputVec.end());
    clock_t startDeq = clock();
    PmergeMe::sort(deq);
    clock_t endDeq = clock();
    size_t deq_comparisons = PmergeMe::getComparisons();

    std::cout << "After: ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << " " << vec[i];
    std::cout << std::endl;

    double timeVec = 1e6 * (static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC);
    double timeDeq = 1e6 * (static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC);

    std::cout << "Time to process a range of " << inputVec.size()
              << " elements with std::vector : "
              << std::fixed << std::setprecision(5) << timeVec << " us"
              << " (Comparisons: " << vec_comparisons << ")" << std::endl;

    std::cout << "Time to process a range of " << inputVec.size()
              << " elements with std::deque  : "
              << std::fixed << std::setprecision(5) << timeDeq << " us"
              << " (Comparisons: " << deq_comparisons << ")" << std::endl;
    // std::cout << "Theoretical minimum comparisons: " << theoreticalUpperBound(inputVec.size()) << std::endl;

    return 0;
}
