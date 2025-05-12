#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type(type) {
    std::cout << "AMateria of type " << type << " created" << std::endl;
}

AMateria::AMateria(const AMateria& other) : type(other.type) {
    std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other) {
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

AMateria::~AMateria() {
    std::cout << "AMateria of type " << type << " destroyed" << std::endl;
}

std::string const & AMateria::getType() const {
    return type;
}

void AMateria::use(ICharacter& target) {
    std::cout << "* uses " << type << " materia on " << target.getName() << " *" << std::endl;
}
