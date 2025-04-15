#include "Zombie.hpp"

int main() {
    Zombie* zombie = newZombie("default");
    zombie->announce();
    delete zombie;
    randomChump("random");
    return 0;
}