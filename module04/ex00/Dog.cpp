#include "Dog.hpp"

Dog::Dog() : Animal() {
    this->type = "Dog";
    std::cout << "A loyal dog wags its tail as it appears." << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "A dog is cloned, twice the happiness!" << std::endl;
}

Dog::~Dog() {
    std::cout << "A good dog takes its final nap." << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        std::cout << "A dog learns another dog's traits." << std::endl;
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}