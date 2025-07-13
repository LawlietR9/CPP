#include <iostream>
#include <cstdlib>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void) {
	int i = rand() % 3;
	if (i == 0)
		return new A;
	else if (i == 1)
		return new B;
	else
		return new C;
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (std::exception &e) {}
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (std::exception &e) {}
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (std::exception &e) {}
}

int main() {
    srand(time(NULL));
	Base *p = generate();
	identify(p);
	identify(*p);
	delete p;
	return 0;
}
