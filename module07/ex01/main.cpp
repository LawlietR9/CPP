#include "iter.hpp"

int main() {
    int tab[] = {0, 1, 2, 3, 4};
    char tab2[] = "abcde";

    iter(tab, 5, print<int>);
    iter(tab2, 5, print<char>);

    return 0;
}
