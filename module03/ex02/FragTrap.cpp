#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap " << name << " is assembled and ready for action!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap " << this->name << " is cloned and ready!" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << name << " says goodbye and powers down!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        std::cout << "FragTrap " << this->name << " is reconfigured to match " << other.name << std::endl;
    }
    return *this;
}

void FragTrap::attack(const std::string& target) {
    if (this->energyPoints == 0) {
        std::cout << "FragTrap " << this->name << " is out of energy!" << std::endl;
        return;
    }
    if (this->hitPoints == 0) {
        std::cout << "FragTrap " << this->name << " is too damaged to attack!" << std::endl;
        return;
    }
    this->energyPoints--;
    std::cout << "FragTrap " << this->name << " launches an epic attack on " << target 
              << ", dealing " << this->attackDamage << " points of damage!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount) {
    if (this->hitPoints == 0) {
        std::cout << "FragTrap " << this->name << " is already knocked out!" << std::endl;
        return;
    }
    if (amount >= this->hitPoints) {
        this->hitPoints = 0;
    } else {
        this->hitPoints -= amount;
    }
    std::cout << "FragTrap " << this->name << " takes " << amount 
              << " points of damage! HP remaining: " << this->hitPoints << std::endl;
}

void FragTrap::beRepaired(unsigned int amount) {
    if (this->energyPoints == 0) {
        std::cout << "FragTrap " << this->name << " has no energy for repairs!" << std::endl;
        return;
    }
    if (this->hitPoints == 0) {
        std::cout << "FragTrap " << this->name << " is too damaged for repairs!" << std::endl;
        return;
    }
    this->energyPoints--;
    this->hitPoints += amount;
    std::cout << "FragTrap " << this->name << " repairs " << amount 
              << " points of damage! HP now: " << this->hitPoints << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << name << " enthusiastically requests high fives from everyone! ✋" << std::endl;
}