#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) {
    this->name = name;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
    std::cout << "ClapTrap " << name << " is created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " is destroyed" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target) {
    if (this->energyPoints == 0) {
        std::cout << "ClapTrap " << this->name << " has no energy points left to attack!" << std::endl;
        return;
    }
    if (this->hitPoints == 0) {
        std::cout << "ClapTrap " << this->name << " has no hit points left to attack!" << std::endl;
        return;
    }
    this->energyPoints--;
    std::cout << "ClapTrap " << this->name << " attacks " << target 
              << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->hitPoints == 0) {
        std::cout << "ClapTrap " << this->name << " is already destroyed!" << std::endl;
        return;
    }
    if (amount >= this->hitPoints) {
        this->hitPoints = 0;
    } else {
        this->hitPoints -= amount;
    }
    std::cout << "ClapTrap " << this->name << " takes " << amount 
              << " points of damage! Hit points left: " << this->hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->energyPoints == 0) {
        std::cout << "ClapTrap " << this->name << " has no energy points left to repair!" << std::endl;
        return;
    }
    if (this->hitPoints == 0) {
        std::cout << "ClapTrap " << this->name << " has no hit points left to repair!" << std::endl;
        return;
    }
    this->energyPoints--;
    this->hitPoints += amount;
    std::cout << "ClapTrap " << this->name << " repairs itself for " << amount 
              << " points! Hit points now: " << this->hitPoints << std::endl;
}