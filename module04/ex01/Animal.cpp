#include "Animal.hpp"

Animal::Animal() : type("Unknown") {
    std::cout << "An unknown creature emerges from the void." << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "A mysterious being is cloned." << std::endl;
}

Animal::~Animal() {
    std::cout << "A creature returns to the void." << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        type = other.type;
        std::cout << "A creature transforms its essence." << std::endl;
    }
    return *this;
}

void Animal::makeSound() const {
    std::cout << "* silence of the unknown *" << std::endl;
}

std::string Animal::getType() const {
    return type;
}