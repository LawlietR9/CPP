#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    Zombie* zombies = new Zombie[N];
    for (int i = 0; i < N; i++) {
        zombies[i].setName(name);
        std::cout << name << " spawned" << std::endl;
    }
    return zombies;
}