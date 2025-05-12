#include "Cat.hpp"

Cat::Cat() : Animal() {
    this->type = "Cat";
    std::cout << "A graceful cat materializes with elegance." << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "A cat is cloned, double the mischief!" << std::endl;
}

Cat::~Cat() {
    std::cout << "A cat gracefully departs for its next life." << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
        std::cout << "A cat mirrors another cat's essence." << std::endl;
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow~ Meow~" << std::endl;
}