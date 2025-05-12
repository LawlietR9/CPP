#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongUnknown") {
    std::cout << "A bizarre creature appears... something seems off." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
    std::cout << "A bizarre creature is duplicated... strangely." << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "A bizarre creature fades away... awkwardly." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other) {
        type = other.type;
        std::cout << "A bizarre creature changes... incorrectly." << std::endl;
    }
    return *this;
}

void WrongAnimal::makeSound() const {
    std::cout << "* strange and incorrect noises *" << std::endl;
}

std::string WrongAnimal::getType() const {
    return type;
}