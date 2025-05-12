#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain created" << std::endl;
}

Brain::Brain(const Brain &other) {
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; ++i) {
        ideas[i] = other.ideas[i];
    }
}

Brain& Brain::operator=(const Brain &other) {
    if (this != &other) {
        for (int i = 0; i < 100; ++i) {
            ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destroyed" << std::endl;
}