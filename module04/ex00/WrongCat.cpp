#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
    this->type = "WrongCat";
    std::cout << "A peculiar feline entity materializes... oddly." << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "A peculiar feline entity is replicated... unnaturally." << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "A peculiar feline entity dissipates... mysteriously." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other) {
        WrongAnimal::operator=(other);
        std::cout << "A peculiar feline entity transforms... strangely." << std::endl;
    }
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << "* distorted meowing sounds *" << std::endl;
}