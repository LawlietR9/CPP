#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    const int numAnimals = 4;
    AAnimal* animals[numAnimals];

    // Create half Dogs and half Cats
    for (int i = 0; i < numAnimals / 2; i++) {
        animals[i] = new Dog();
    }
    for (int i = numAnimals / 2; i < numAnimals; i++) {
        animals[i] = new Cat();
    }

    std::cout << "\n--- Testing deep copy for Dog ---" << std::endl;
    {
        Dog *original = new Dog();
        original->getBrain()->ideas[0] = "Chasing cars";
        Dog copy = *original; // Copy construction
        copy.getBrain()->ideas[0] = "Barking at mailman";
        std::cout << "Original Dog brain idea: " << original->getBrain()->ideas[0] << std::endl;
        std::cout << "Copied Dog brain idea: " << copy.getBrain()->ideas[0] << std::endl;
        delete original;
    }

    std::cout << "\n--- Testing deep copy for Cat ---" << std::endl;
    {
        Cat *original = new Cat();
        original->getBrain()->ideas[0] = "Sleeping on the couch";
        Cat copy = *original; // Copy construction
        copy.getBrain()->ideas[0] = "Scratching furniture";
        std::cout << "Original Cat brain idea: " << original->getBrain()->ideas[0] << std::endl;
        std::cout << "Copied Cat brain idea: " << copy.getBrain()->ideas[0] << std::endl;
        delete original;
    }

    std::cout << "\n--- Cleaning up the Animal array ---" << std::endl;
    for (int i = 0; i < numAnimals; i++) {
        delete animals[i];
    }
    
    return 0;
}