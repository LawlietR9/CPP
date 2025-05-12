#include "Ice.hpp"
#include "ICharacter.hpp"
Ice::Ice() : AMateria("ice") {
    std::cout << "Ice materia created" << std::endl;
}
Ice::Ice(const Ice &other) : AMateria(other) {
    std::cout << "Ice materia copy constructor called" << std::endl;
}
Ice &Ice::operator=(const Ice &other) {
    if (this != &other) {
        AMateria::operator=(other);
    }
    return *this;
}
Ice::~Ice() {
    std::cout << "Ice materia destroyed" << std::endl;
}
AMateria* Ice::clone() const {
    return new Ice(*this);
}
void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
