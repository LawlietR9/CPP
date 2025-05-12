#include <iostream>
#include "Character.hpp"
#include "Ice.hpp"

int main() {
    std::cout << "Testing AMateria and ICharacter interface" << std::endl;
    Character bob("Bob");
    Ice ice;
    AMateria* iceClone = ice.clone();
    ice.use(bob);
    iceClone->use(bob);
    delete iceClone;
    return 0;
}