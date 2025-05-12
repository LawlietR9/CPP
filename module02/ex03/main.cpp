#include "Point.hpp"
#include <iostream>

int main() {
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    Point inside(2, 2);
    Point outside(20, 20);
    Point onEdge(5, 0);

    std::cout << "Point inside: " << bsp(a, b, c, inside) << std::endl; // Should print 1 (true)
    std::cout << "Point outside: " << bsp(a, b, c, outside) << std::endl; // Should print 0 (false)
    std::cout << "Point on edge: " << bsp(a, b, c, onEdge) << std::endl; // Should print 0 (false)

    return 0;
}
